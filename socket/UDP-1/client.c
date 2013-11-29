#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include "wrap.h"

#define MAXLINE 80
#define SERV_PORT 8000

struct info_t
{
	int no;
	//unsigned char data;
	int data;
};
int main(int argc, char *argv[])
{
	struct sockaddr_in servaddr;
	int sockfd, n;
	struct info_t info;
	char str[INET_ADDRSTRLEN];
	socklen_t servaddr_len;

	sockfd = Socket(AF_INET, SOCK_DGRAM, 0);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	inet_pton(AF_INET, argv[1], &servaddr.sin_addr);
	servaddr.sin_port = htons(SERV_PORT);

	int i = 0;
	for (i  = 0; i < 1000; i++)
	{
		info.no = i;
		info.data = i;
		sendto(sockfd, &info, sizeof(struct info_t), 0, (struct sockaddr *)&servaddr, sizeof(servaddr));
	}
	for (i  = 0; i < 1000; i++)
	{
		recvfrom(sockfd, &info, sizeof(struct info_t), 0, NULL, 0);
		printf("%d\n", info.data);
usleep(5000);
	}
	Close(sockfd);
	return 0;
}
