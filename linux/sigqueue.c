#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	pid_t pid;
	pid = fork();
	if (pid > 0)
	{
		while(1);
	}
	else if(pid ==0)
	{
		printf("%d\n", (int)setsid());
		while(1);
	}
	else{
		exit(-1);
	}
	return 0;

}
