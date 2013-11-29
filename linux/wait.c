#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	pid_t pid;
	pid = fork();
	int stat;
	if(pid > 0)
	{
		//printf(" child is %d\n", wait(NULL));
		printf(" child is %d\n", wait(&stat));
		printf("child exit stat is %d\n",WEXITSTATUS(stat));
		return 0;
	}
	else if(pid == 0)
	{
		sleep(1);
		printf("I am is %d\n", getpid());
		exit(-1);
	}
	else 
	{
		perror("fork");
		exit(-1);
	}
	return 0 ;
}
