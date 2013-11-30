#include <stdlib.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
int main(void)
{
	FILE *fp;
	int i;
	char filename[100];
	i = 3;
	while(1){
		sprintf(filename,"file%d",i);
		fp = fopen(filename,"w");
		if(fp == NULL)
		{
			//printf("error = %d\n",errno);
			//perror("fopen");
			printf(strerror(errno));
			exit(-1);
		}
		//fclose("file%d",i);
		printf("%d\n",i);
		i++;
	}
}
