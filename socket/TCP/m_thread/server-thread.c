#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>
#include <pthread.h>
#include "wrap.h"

#define MAXLINE 80
#define SERV_PORT 8000

struct s_info {
	struct sockaddr_in cliaddr;
	int connfd;
};

void *thr_fn(void *arg)
{
	int i, n;
	struct s_info *p = (struct s_info *)arg;
	char buf[MAXLINE];
	char str[INET_ADDRSTRLEN];

	pthread_detach(pthread_self());
	while(1)
	{
		n = Read(p->connfd, buf, MAXLINE);
		if (n == 0)
		{
			printf("the other side has been closed.\n");
			break;
		}
		printf("received from %s at PROT %d\n", inet_ntop(AF_INET, &((*p).cliaddr.sin_addr), str, sizeof(str)), ntohs((*p).cliaddr.sin_port));

		for (i = 0; i < n; i++)
			buf[i] = toupper(buf[i]);
		Write(p->connfd, buf, n);
	}
	Close(p->connfd);
	return 0;
}
int main(void)
{
	pthread_t tid;
	struct s_info ts[383];
	struct sockaddr_in servaddr, cliaddr;
	socklen_t cliaddr_len;
	int i = 0, err, listenfd, connfd;

	listenfd = Socket(AF_INET, SOCK_STREAM, 0);
	int opt = 1;
	setsockopt(listenfd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(SERV_PORT);

	Bind(listenfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

	Listen(listenfd, 20);

	printf("Accepting connections ...\n");
	while(1)
	{
		cliaddr_len = sizeof(cliaddr);//传入传出参数
		connfd = Accept(listenfd, (struct sockaddr *)&cliaddr, &cliaddr_len);
		ts[i].cliaddr = cliaddr;
		ts[i].connfd = connfd;
		err = pthread_create(&tid, NULL, thr_fn, (void *)&ts[i]);
		if (err !=  0)
		{
			fprintf(stderr, "can't create thread: %s\n", strerror(err));
			exit(1);
		}
		i++;
	}
	return 0;
}
