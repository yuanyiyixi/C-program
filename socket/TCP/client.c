#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define MAXLINE 80
#define SERV_PORT 8000

int main(int argc, char *argv[])
{
	struct sockaddr_in servaddr;
	char buf[MAXLINE];
	int sockfd, n;
	char *str;

	if (argc != 3)
	{
		fputs("usage: ./client message ip\n", stderr);
		exit(1);
	}
	str = argv[1];

	sockfd = socket(AF_INET, SOCK_STREAM, 0);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	inet_pton(AF_INET, argv[2], &servaddr.sin_addr);
	servaddr.sin_port = htons(SERV_PORT);

	connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

	write(sockfd, str, strlen(str));
	printf("Response from server:\n");
	while(1)
	{
	n = read(sockfd, buf, MAXLINE);
	if (n == 0)
		break;
	write(STDOUT_FILENO, buf, n);
	}

	close(sockfd);
	return 0;
}
