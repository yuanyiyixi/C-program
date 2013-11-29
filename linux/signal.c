#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int i = 0;
int j = 0;

void  do_sig(int num)
{
	printf("bbb\n");
	return ;
}
int main(void)
{
	signal(SIGINT,do_sig);
	sleep(2);
	j ++;
	++i;
#if 0
	while(1)
	{
		printf("aaaaa\n");
		sleep(1);
	}
#endif
	return 0;
}
