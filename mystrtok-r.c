#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char *mystrtok_r(char *str,const char *delim,char **saveptr)
{
	static char *tmp = NULL; 
	const char *p = delim;
	if(str != NULL)
		tmp = str;
	if(tmp == NULL || p == NULL)
		return NULL;
	//*saveptr[] = tmp;
	tmp = *saveptr; 
	char *q = tmp;
	while(*tmp != '\0')
	{
		while(*p){
			if(*tmp != *p)
			{
				p++;
				continue;
			}
			else
			{
				*tmp = '\0';
				tmp++;
				*saveptr = tmp;
				**saveptr++;
				return q;
			}
		}
		p = delim;
		tmp++;
	}
	if(*tmp == '\0')
		tmp = NULL;
		return q ;
}
int main(int argc, char *argv[])
{
	char *str1,*str2, *token, *subtoken;
	char *saveptr1,*saveptr2;
	int j;

	if(argc < 2)
	{
		printf("Please enter ./a.out num:\n");
		exit(-1);
	}

	  for(j = 1,str1= argv[1];;j++,str1 = NULL){
		  token = mystrtok_r(str1,argv[2],&saveptr1);
		  if(token == NULL)
			  break;
			  printf("%d:%s\n", j, token);
			  
			  for(str2 = token;;str2 = NULL)
			  {
				  subtoken = mystrtok_r(str2, argv[3],&saveptr2);
				  if(subtoken == NULL)
					  break;
					  printf("--> %s\n",subtoken);
			  }
	  }
	return 0;
}
