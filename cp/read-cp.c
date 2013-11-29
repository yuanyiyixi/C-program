#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
	int fd1, fd2;
	char buf[1024];
	int len = 1;
	if (argc < 3)
	{
		printf("please enter ./a.out file file\n");
		exit(-1);
	}

	fd1 = open(argv[1],O_RDONLY);
	if (fd1 < 0)
		exit(-1);
	fd2 = open(argv[2],O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if (fd2 < 0)
		exit(-1);

	while(len)
	{
		len = read(fd1, buf, sizeof(buf));
		if (len < 0)
			break;
		write(fd2, buf, len);
	}
	close(fd1);
	close(fd2);

	return 0;
}
