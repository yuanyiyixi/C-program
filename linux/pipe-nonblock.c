#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int fd[2];
	int len;
	char buf[4096];
	if (pipe(fd) < 0)
	{
		exit(-1);
	}
	printf("pipe buf = %ld\n", fpathconf(fd[0],_PC_PIPE_BUF));
	pid_t pid;
	pid = fork();
	if(pid < 0)
	{
		perror("fork");
		exit(-1);
	}
	else if(pid == 0)
	{
		int mode;
		close(fd[1]);
		mode = fcntl(fd[0], F_GETFL);
		mode |= O_NONBLOCK;
		fcntl(fd[0], F_SETFL, mode);
		while(1)
		{
			len = read(fd[0], buf, sizeof(buf));
			if (len == 0)
			{
				write(STDOUT_FILENO, "EOF\n",4);
				break;
			}
			else if (len < 0)
			{
				sleep(3);
				write(STDOUT_FILENO, "haha\n",5);
				continue;
			}
			write(STDOUT_FILENO, buf, len);
		}
	}
	else
	{
		while(1)
		{
			len = read(STDIN_FILENO, buf, sizeof(buf));
			write(fd[1], buf, len);
		}
		wait(NULL);
	}
	return 0;
}
