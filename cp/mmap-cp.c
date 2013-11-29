#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <stdio.h>

#define N	4096
int main(int argc, char *argv[])
{
	if (argc < 3)
	{
		printf("please enter ./a.out file1 file2\n");
		exit(-1);
	}
	int fd1, fd2;
	int size, i = 0, j;
	char *p1, *p2;

	fd1 = open(argv[1],O_RDONLY);
	fd2 = open(argv[2], O_RDWR | O_CREAT, 0666);
	if (fd1 < 0 || fd2 < 0)
	{
		perror("open");
		exit(-1);
	}

	size = lseek(fd1, 0, SEEK_END);
	lseek(fd2, size - 1, SEEK_END);
	write(fd2,"\0", 1);	
	//lseek(fd1, 0, SEEK_SET);
	lseek(fd2, 0, SEEK_SET);

	//for (i = 1; i*4096 >= size; i++)
#if 0
		p1 = mmap(NULL, size, PROT_READ, MAP_PRIVATE, fd1, 0);
		p2 = mmap(NULL, size, PROT_WRITE, MAP_SHARED, fd2, 0);

		if(p1 == MAP_FAILED || p2 == MAP_FAILED)
		{
			perror("mmap");
			exit(-1);
		}
		close(fd1);
		close(fd2);
		for (j = 0; j < size; j++)
			p2[j] = p1[j];

		munmap(p1, size);
		munmap(p2, size);
#endif

	for (i = 1; i <= (size / N); i++)
	{
		p1 = mmap(NULL, N, PROT_READ, MAP_PRIVATE, fd1, (i - 1)*N);
		p2 = mmap(NULL, N, PROT_WRITE, MAP_SHARED, fd2, (i - 1)*N);

		if(p1 == MAP_FAILED || p2 == MAP_FAILED)
		{
			perror("mmap");
			exit(-1);
		}
		for (j = 0; j < N; j++)
			p2[j] = p1[j];
		munmap(p1, N);
		munmap(p2, N);
	}
		p1 = mmap(NULL, size % N, PROT_READ, MAP_PRIVATE, fd1, (i - 1)*N);
		p2 = mmap(NULL, size % N, PROT_WRITE, MAP_SHARED, fd2, (i - 1)*N);

		if(p1 == MAP_FAILED || p2 == MAP_FAILED)
		{
			perror("mmap");
			exit(-1);
		}
		for (j = 0; j < (size % N); j++)
			p2[j] = p1[j];
		munmap(p1, size % N);
		munmap(p2, size % N);
		close(fd1);
		close(fd2);


	return 0;
}
