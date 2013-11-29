#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		printf("please enter ./a.out file");
		exit(-1);
	}
	if(!access(argv[1],F_OK)) 
	{
		printf("F_OK\t");
		if( !(access(argv[1], R_OK)))
			printf("R_OK\t");
		else printf("R_ERR\t");
		if( !(access(argv[1], W_OK)))
			printf("W_OK\n");
		else printf("W_ERR\n");
	}
	else printf("F_ERR\n");
#if 0
	//read and write all exist
	if(!access(argv[1],W_OK | R_OK))
		printf("W_OK | R_OK\n");
#endif
	return 0;
}
