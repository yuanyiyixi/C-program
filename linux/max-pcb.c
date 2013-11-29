#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>

int main(void)
{
	pid_t pid;
	int i = 1;

	while(1)
	{
		pid = fork();
		i++;
		if (pid < 0)
		{
			perror("fork");
			exit(1);
		}
		else if(pid == 0)
			break;
		else {
			printf("%d\n", i);
		}
	}
	while(1);
	return 0;
}
		 
