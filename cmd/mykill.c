#include <sys/types.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
	if(argc == 2)
		kill(atoi(argv[1]),9);
	else if(argc == 3)
		kill(atoi(argv[2]),atoi(argv[1]));
	else if (argc < 2)
	{
		printf("./a.out sig pid\n");
		exit(-1);
	}
	return 0;
}
