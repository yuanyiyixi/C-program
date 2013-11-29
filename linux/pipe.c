#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		printf("please enter ./a.out number\n");
		exit(-1);
	}

	pid_t pid;
	int len, fd[2], i;
	char buf[4096];
	if(pipe(fd) < 0)
	{
		perror("pipe");
		exit(-1);
	}
	printf("fd[0] = %d\tfd[1] = %d\n",fd[0],fd[1]);
	pid = fork();
	if(pid < 0)
	{
		perror("fork");
		exit(-1);
	}
	else if(pid == 0)
	{
		close(fd[1]);
		for(i = 0; i < atoi(argv[1]); i++)
		{
			len = read(fd[0], buf, sizeof(buf));
			write(STDOUT_FILENO, buf, len);
		}
		close(fd[0]);
	}
	else
	{
		close(fd[0]);
		for(i = 0; i < atoi(argv[1]); i++)
		{
			len = read(STDIN_FILENO, buf, sizeof(buf));
			write(fd[1], buf, len);
		}
		close(fd[1]);
		wait(NULL);
	}
	return 0;
}

