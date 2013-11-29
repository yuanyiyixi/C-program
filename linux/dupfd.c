#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	int fd1, res, fd2;
	fd1 = open("abc", O_RDWR | O_CREAT, 0666);
	fd2 = open("abc", O_RDWR | O_CREAT, 0666);
	res = fcntl(fd1, F_DUPFD, 3);
	printf("%d ", res);

	if (fd1 < 0 || fd2 < 0)
	{
		perror("open");
		exit(-1);
	}

	write(fd1, "hello ", 6);
	write(res, "world\n", 6);
	write(fd2, "akaedu\n", 7);
	close(fd1);
	close(fd2);
	close(res);
	return 0;
}
