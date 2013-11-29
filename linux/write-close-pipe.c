#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

int main(void)
{
	pid_t pid;
	int fd[2], i, len = 0;
	char buf[4096] = "hello";
	if(pipe(fd) < 0)
	{
		perror("pipe");
		exit(-1);
	}
	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		exit(-1);
	}
	else if(pid == 0)
	{
		close(fd[1]);
	while(1)	
		{
			/*睡眠时间到后可以继续读*/
			//len = read(fd[0],buf,1024);
			//printf("%s len = %d\n",buf,len);
			sleep(10);
		}
		close(fd[0]);
	}
	else
	{
		close(fd[0]);
	while(1)	
		{
			write(fd[1], buf, 6);
			printf("%s len = %d\n",buf,len++);
		}
		close(fd[1]);
		wait(NULL);
	}
	return 0;
}
