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
	fd = open(argv[1], O_CREAT | O_RDWR, 0644);
	if(fd < 0)
	{
		perror("open");
		exit(-1);
	}
	lseek(fd, 4095, SEEK_SET);
	write(fd, "a",1);
	mem = mmap(NULL, 4096, PROT_WRITE, MAP_SHARED, fd, 0);
	if (mem == MAP_FAILED)
	{
		perror("mmap");
		exit(-1);
	}
	int i = 0;
	while(1)
	{
		mem->id = i++;
		sprintf(mem->name, "hello %d", i++);
		if(i % 2)
			mem->sex = 'm';
		else
			mem->sex = 'w';
		sleep(2);
	}
	close(fd);
	munmap(mem, 4096);
	return 0;
}
