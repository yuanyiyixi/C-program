#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	pid_t pid;
	int i, fd1[2], fd2[2];
	int len;
	char *num;
	*num = 15;
	if(pipe(fd1) < 0 || pipe(fd2) < 0)
	{
		perror("pipe");
		exit(-1);
	}

	//printf("fd[0] = %d\tfd[1] = %d\n",fd[0],fd[1]);
	for (i = 0; i < 3; i++)
	{
		pid = fork();
		if(pid < 0)
		{
			perror("fork");
			exit(-1);
		}
		else if(pid == 0)
			break;
	}

	if(pid == 0)
	{
		switch(i)
		{
			case 0:
				close(fd2[0]);
				close(fd2[1]);
				close(fd1[0]);
				printf("I am %d, num is %d\n", getpid(), *num);
				write(fd1[1], num,1);
				close(fd1[1]);
				break;
			case 1:
				close(fd1[1]);
				close(fd2[0]);
				len = read(fd1[0],num, 1);
				(*num)++;
				printf("I am %d, num is %d\n", getpid(), *num);
				write(fd2[1], num , 1);
				close(fd1[0]);
				close(fd2[1]);
				break;
			case 2:
				close(fd1[0]);
				close(fd1[1]);
				close(fd2[1]);
				len = read(fd2[0],num, 1);
				(*num)++;
				printf("I am %d, num is %d\n", getpid(), *num);
				close(fd2[0]);
				break;
		}
	}
	else//(pid > 0)
	{
		close(fd1[0]);
		close(fd1[1]);
		close(fd2[0]);
		close(fd2[1]);
				printf("father %d, num is %d\n", getpid(), *num);
	for (i = 0; i < 3; i++)
		wait(NULL);
	}
	return 0;
}

