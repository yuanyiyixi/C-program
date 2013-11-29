#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <time.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include "wrap.h"

#define MAXLINE 80
#define SERV_PORT 8000

void do_sig(int signo)
{
	waitpid(0, NULL, WNOHANG);
}
int main(void)
{
	struct sockaddr_in servaddr, cliaddr;
	socklen_t cliaddr_len;
	int listenfd, connfd;
	char buf[MAXLINE];
	char str[INET_ADDRSTRLEN];
	int i, n;
	pid_t pid;
	time_t t;

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
		pid = fork();
		if (pid < 0)
		{
			perror("call to fork");
			exit(1);
		}
		else if(pid ==0)
		{
			close(listenfd);
			while(1)
			{
				n = Read(connfd, buf, MAXLINE);
				if (n == 0)
				{
					printf("the other side has been closed.\n");
					break;
				}
				printf("received from %s at PROT %d\n", inet_ntop(AF_INET, &cliaddr.sin_addr, str, sizeof(str)), ntohs(cliaddr.sin_port));

				for (i = 0; i < n; i++)
					buf[i] = toupper(buf[i]);
				Write(connfd, buf, n);
			}
			Close(connfd);
			return 0;
		}
		else
		{
			struct sigaction newact;
			newact.sa_handler = do_sig;
			sigemptyset(&newact.sa_mask);
			newact.sa_flags = 0;
			sigaction(SIGCHLD, &newact, NULL);

			Close(connfd);
		}
	}
}
