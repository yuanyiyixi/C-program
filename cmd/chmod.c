#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#if 0
int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		printf("please enter ./a.out mode file\n");
		exit(-1);
	}
#if 0	
	int mode = (argv[1][0] - '0') * 8 * 8 + (argv[1][1] - '0') * 8 + (argv[1][2] -'0');
#endif
#if 1
	int mode = (argv[1][0] - '0') << 6 | (argv[1][1] - '0') << 3 |(argv[1][2] - '0') << 0;
#endif
	if(chmod(argv[2], mode))
	{
		perror("chmod");
		exit(-1);
	}

	return 0;
}
#endif
int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		exit(1);
	}

	int mode = (argv[1][0] - '0') << 6 | (argv[1][1] - '0') << 3 | (argv[1][2] - '0') << 0;

	if (chmod(argv[2], mode))
	{
		perror("chmod");
		exit(1);
	}

	return 0;
}
