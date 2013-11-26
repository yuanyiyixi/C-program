#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if (argc < 3)
		load("dict.txt");
	else if(strcmp(argv[1],"-f") == 0 )
	if(load (argv[2]) == 1)
	{
		printf("load failed\n");
		exit(-1);
	}
	while(1)
	{
		char buf[128];
		printf("search$$ ");
		fgets(buf, 128, stdin);
		if(strcmp(buf,"exit\n") == 0)
			break;
		parse(buf, &argc, &argv);
		search(argv);
	}
	return 0;
}
