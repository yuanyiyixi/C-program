#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
	if(argc < 3)
	{
		printf("./a.out src dest\n");
		exit(-1);
	}

	FILE *fp,*fp2;
	char buf[1024];
	char *p, *token; 
	char s[] = ")('";
	static int count = 0,count1 = 0;

	fp = fopen(argv[1],"r");
	if(fp == NULL)
	{
		perror("fopen");
		exit(-1);
	}
	while(fgets(buf,sizeof(buf),fp) != NULL)
	{
		//token = strtok(buf,s);	
		p  = buf;
		while(*p)
		{
			if(strstr(p,"she") != NULL)//||((p = strstr(p,"She")) != NULL)) 
			{
				p = strstr(p,"she");
				count++;
			}
			p += 3;
		}
		p = buf;
		while(*p)
		{
			if(strstr(p,"She") != NULL)//||((p = strstr(p,"She")) != NULL)) 
			{
				p = strstr(p,"She");
				count++;
			}
			p += 3;
		}
		p = buf;
		while(*p)
		{
			if(strstr(p,"like") != NULL)//||((p = strstr(p,"She")) != NULL)) 
			{
				p = strstr(p,"like");
				count1++;
			}
			p += 4;
		}
		p = buf;
		while(*p)
		{
			if(strstr(p,"Like") != NULL)//||((p = strstr(p,"She")) != NULL)) 
			{
				p = strstr(p,"Like");
				count1++;
			}
			p += 4;
		}
	}
	fp2 = fopen(argv[2],"w+");
	if(fp2 == NULL)
	{
		perror("fopen");
		exit(-1);
	}
	fprintf(fp2,"she: %d\tlike:%d\n",count,count1);
	fclose(fp);
	fclose(fp2);
	return 0;
}
