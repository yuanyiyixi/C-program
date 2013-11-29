#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int main(void)
{
	int fd;
	char buf[4096];
	ssize_t n;
	pid_t pid;
	pid = fork();
	if(pid > 0)
	{
		fd = open("abc",O_WRONLY | O_APPEND , 0644);
		while(1)
		{
			sleep(1);
			n = read(0, buf, sizeof(buf));
			write(fd, buf, n); 
		}
		close(fd);
	}
	else if (pid == 0)
	{
		fd = open("abc",O_RDONLY , 0644);
		while(1)
		{
			sleep(3);
			n = read(fd, buf, sizeof(buf));
			write(1, buf, n);
		}
		close(fd);
	}
	else{
		perror("fork");
		exit(-1);
	}
	return 0;
}
