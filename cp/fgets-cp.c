#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
	if(argc < 3)
	{
		printf("./a.out src dest:\n");
		exit(-1);
	}
	FILE *fp, *gp;
	char buf[1024];
	fp = fopen(argv[1], "r");
	if(fp == NULL)
	{
		perror("fopen");
		exit(-1);
	}
	gp = fopen(argv[2], "w");
	if(gp == NULL)
	{
		perror("fopen");
		exit(-1);
	}
	while(fgets(buf,sizeof(buf),fp))
		fputs(buf,gp);

		fclose(fp);
		fclose(gp);
		return 0;
}
