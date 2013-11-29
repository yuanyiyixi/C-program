#include <stdio.h>
#include <string.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "wrap.h"

#define MAXLINE 80
#define SERV_PORT 8000

struct info_t
{
	int no;
	//unsigned char data;
	int data;
};
int main(void)
{
	struct sockaddr_in servaddr, cliaddr;
	socklen_t cliaddr_len;
	int sockfd;
	struct info_t info;
	char str[INET_ADDRSTRLEN];
	int i, n;

	sockfd = Socket(AF_INET, SOCK_DGRAM, 0);

	bzero(&servaddr, sizeof(servaddr));
	servaddr.sin_family = AF_INET;
	servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
	servaddr.sin_port = htons(SERV_PORT);

	Bind(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr));

	printf("Accpeting connections ...\n");
	while(1)
	{
		cliaddr_len = sizeof(cliaddr);
		n = recvfrom(sockfd, &info, sizeof(struct info_t), 0, (struct sockaddr *)&cliaddr, &cliaddr_len);
		if (n == -1)
			perr_exit("recvfrom error");
		printf("received from %s at PORT %d\n", inet_ntop(AF_INET, &cliaddr.sin_addr, str, sizeof(str)), ntohs(cliaddr.sin_port));
		usleep(1);

		/*for (i = 0; i < n; i++)
			buf[i] = toupper(buf[i]);*/
		printf("%d\n", info.data);
		info.data += 100;
		n = sendto(sockfd, &info, sizeof(struct info_t), 0, (struct sockaddr *)&cliaddr, sizeof(cliaddr));
		if(n == -1)
			perr_exit("sendto error");
	}
}
