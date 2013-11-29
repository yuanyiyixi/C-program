#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>

int main(void)
{
	pid_t pid;
	int i = 0 ;
	int fd =  open("abc", O_RDWR | O_CREAT, 0755);
	pid = fork();
	if (pid > 0)
	{
		write(fd, "hello", 5);
	}
	else if(pid == 0)
	{
		execl("exec","./exec",NULL);
		write(fd, "world",5);
	}
	else {
		perror("fork");
		exit(1);
	}
	close(fd);
	return 0;
}
