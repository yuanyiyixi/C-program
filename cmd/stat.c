#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		printf("please enter ./a.out file");
		exit(-1);
	}
	struct stat buf;
	int i = 0;
	lstat(argv[1], &buf);
	if(S_ISREG(buf.st_mode))
		printf("-");
	else if(S_ISDIR(buf.st_mode))
		printf("d");
	else if(S_ISCHR(buf.st_mode))
		printf("c");
	else if(S_ISBLK(buf.st_mode))
		printf("b");
	else if(S_ISLNK(buf.st_mode))
		printf("l");
	else if(S_ISFIFO(buf.st_mode))
		printf("p");

	for(i = 2; i >= 0; i--)
	{
		switch((buf.st_mode  >> (i*3)) & 0x7)
		{
			case 7:printf("rwx");break;
			case 6:printf("rw-");break;
			case 5:printf("r-x");break;
			case 4:printf("r--");break;
			case 3:printf("-wx");break;
			case 2:printf("-w-");break;
			case 1:printf("--x");break;
			case 0:printf("---");break;
		}
	}
	printf("\t");

	printf("%d\n",(int)buf.st_size);

	return 0;
}
