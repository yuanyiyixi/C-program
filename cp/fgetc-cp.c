#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	FILE *fp,*gp;
	char ch;
	if(argc < 3)
	{
		printf("./a.out src dest\n");
		exit(-1);
	}
	fp = fopen(argv[1],"r");
	if(fp == NULL){
		perror("fopen");
		exit(-1);
	}

//	while((ch = fgetc(stdin)) != EOF)
//		 fputc(ch,fp);
		
	gp = fopen(argv[2],"w");
	//fp = fopen("abc","r");
	if(gp == NULL){
		perror("fopen");
		exit(-1);
	}
		while((ch = fgetc(fp)) != EOF)
		fputc(ch, gp);

	fclose(fp);
	fclose(gp);

	return 0;
}
