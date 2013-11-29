#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
	int fd, len;
	char buf[4096];
	if (argc < 2)
	{
		printf("./a.out pipename\n");
		exit(-1);
	}
	fd = open(argv[1], O_WRONLY);
	if (fd < 0)
	{
		perror("open");
		exit(-1);
	}
	len = read(STDIN_FILENO, buf, sizeof(buf));
	write(fd, buf,len);
	close(fd);
	return 0;
}
