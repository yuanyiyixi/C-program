#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/types.h>
#include <sys/fcntl.h>
#include <sys/stat.h>
#include "wrap.h"

#define MAXLINE 262068 
#define SERV_PORT 8000

int main(void)
{
	int listenfd, connfd, fd;
	char buf[MAXLINE];
	char str[MAXLINE];
	char *p, *q;
	int i = 0, n;
	struct sockaddr_in servaddr, cliaddr;
	socklen_t cliaddr_len;

	listenfd = Socket(AF_INET, SOCK_STREAM, 0);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(SERV_PORT);
	int opt = 1;
	setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

	Bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

	Listen(listenfd, 20);

	while(1)
	{
		cliaddr_len = sizeof(cliaddr);
		connfd = Accept(listenfd, (struct sockaddr *)&cliaddr, &cliaddr_len);
#if 0
		pid_t pid = fork();
		if (pid < 0)
		{
			perror("fork");
			exit(-1);
		}
		else if(pid == 0)
		{
			close(listenfd);
#endif
			n = Read(connfd, buf, sizeof(buf));
			buf[n] = 0;
			p = strtok(buf, "/");
			p = strtok(NULL, " ");

			fd = open(p, O_RDONLY);
			printf("%s\n", p);

			q = rindex(p,'.');
			printf("%s\n", q + 1);
			if (strcmp(q  + 1, "png") == 0)
				sprintf(buf, "HTTP/1.1 200 OK\r\nContent-Type: image/png\r\n\n");
			else
				sprintf(buf, "HTTP/1.1 200 OK\r\nContent-Type: text/html\r\n\n");
			//strcat(buf,str);
			Write(connfd, buf, strlen(buf));
			while(n = Read(fd, str, 1024)) 
				Write(connfd, str, n);
			Close(fd);
			Close(connfd);
		//}
		//else
		//	close(connfd);
	}
	return 0;
}
