#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(void)
{
	FILE * fp;
	char buf[1024];
	int len;
	fp = fopen("abc","w");
	memset(buf,0,sizeof(buf));
	if(fp == NULL)
	{
		perror("fopen");
		exit(-1);
	}
	while(fread(buf,1,sizeof(buf),stdin))
	{
		fwrite(buf,1,sizeof(buf),fp);
	}
	fclose(fp);
	return 0;
}
