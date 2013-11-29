#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <wait.h>
#include "wrap.h"

#define MAXLINE 80
#define SERV_PORT 8000

int main(int argc, char *argv[])
{
	struct sockaddr_in servaddr;
	char buf[MAXLINE];
	int sockfd, n;

	if (argc != 2)
	{
		fputs("usage: ./client ip\n", stderr);
		exit(1);
	}

	pid_t pid;
	int i ;
	for (i = 0; i < 10; i++)
	{
		pid = fork();
		if (pid < 0)
			exit(-1);
		else if(pid == 0)
			break;
	}
	if (pid  == 0)
	{
		sockfd = Socket(AF_INET, SOCK_STREAM, 0);

		bzero(&servaddr, sizeof(servaddr));
		servaddr.sin_family = AF_INET;
		inet_pton(AF_INET, argv[1], &servaddr.sin_addr);
		servaddr.sin_port = htons(SERV_PORT);

		Connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));
		while(fgets(buf, MAXLINE, stdin) != NULL)
		{
			Write(sockfd, buf, strlen(buf));
			n = Read(sockfd, buf, MAXLINE);
			if (n == 0)
				printf("the other side has been closed.\n");
			else
				Write(STDOUT_FILENO, buf, n);
		}
		Close(sockfd);
	}
	for (i = 0; i < 10; i++)
		wait(NULL);
	Close(sockfd);
	return 0;
}
