#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <string.h>
#include <time.h>

void daemonize(void)
{
	pid_t pid;
	int fd;
	time_t timep;
	if ((pid = fork()) < 0)
	{
		perror("fork");
		exit(1);
	}
	else if(pid != 0)
		exit(0);
	setsid();

	if(chdir("/") < 0)
	{
		perror("chdir");
		exit(1);
	}

	fd = open("/tmp/dameon.log", O_RDWR | O_CREAT| O_APPEND, 0666);
	dup2(fd, 0);
	dup2(fd, 1);
	dup2(fd, 2);

	while(1)
	{
		time(&timep);
		write(0,ctime(&timep),strlen(ctime(&timep)));
		//printf("%s\n", ctime(&timep));
		sleep(10);
	}
}

int main(void)
{
	daemonize();
	return 0;
}
