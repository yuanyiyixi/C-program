#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/mman.h>

struct STU{
	int id;
	char sex;
	char name[20];
};

int main(int argc, char *argv[])
{
	int fd;
	struct STU *mem;
	if(argc < 2)
	{
		printf("./a.out filename\n");
		exit(-1);
	}
	fd = open(argv[1], O_RDWR);
	if(fd < 0)
	{
		perror("open");
		exit(-1);
	}
	mem = mmap(NULL, 4096, PROT_READ, MAP_SHARED, fd, 0);
	if (mem == MAP_FAILED)
	{
		perror("mmap");
		exit(-1);
	}
	int i = 0;
	while(1)
	{
		//read(fd,mem,sizeof(mem));
		write(STDOUT_FILENO, mem, 28);
		sleep(1);
	}
	close(fd);
	munmap(mem, 4096);
	return 0;
}
