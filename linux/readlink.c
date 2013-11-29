#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		printf("please enter ./a.out file");
		exit(-1);
	}
	char buf[4096];
	readlink(argv[1], buf, 4096);
	strcat(buf,"\0");
	printf("%s\n",buf);

	return 0;
}
