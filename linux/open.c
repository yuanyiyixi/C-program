#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int fd, i;
	close(1);

		 fd = open("abc",O_CREAT | O_WRONLY,0666);
		if (fd == -1)
			exit(-1);
		 printf("hello world\n");
	return 0;
}
