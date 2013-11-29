#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc,char *argv[])
{
	if(argc < 2)
	{
		printf("./a.out src dest");
		exit(-1);
	}
	FILE *fp,*gp;
	char buf[32];	
	int len;
	fp = fopen(argv[1],"r");
	if(fp == NULL)
	{
		perror("fopen");
		exit(-1);
	}
	gp = fopen(argv[2],"w");
	if(fp == NULL)
	{
		perror("fopen");
		exit(-1);
	}
	while(len = fread(buf,1,sizeof(buf),fp))
		fwrite(buf,1,len,gp);
	fclose(fp);
	fclose(gp);
	return 0;
}
