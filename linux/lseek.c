#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int fd, size;
	fd = open("abc",O_WRONLY);
	if (fd < 0)
		exit(-1);

	size = lseek(fd, 0, SEEK_END);
	lseek(fd, 100, SEEK_END);
	write(fd, "a", 1);

	close(fd);
	return 0;
}
