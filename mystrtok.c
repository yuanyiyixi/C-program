#include <stdio.h>
#include <string.h>
char *mystrtok(char *str,const char *delim)
{
	static char *tmp = NULL; 
	const char *p = delim;
	if(str != NULL)
		tmp = str;
	if(tmp == NULL || p == NULL)
		return NULL;
	char *q = tmp;
	while(*tmp != '\0')
	{
		//for(;*p != '\0';p++)
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
				return q;
			}
		}
		p = delim;
		tmp++;
	}
	if(*tmp == '\0')
		tmp = NULL;
		return q ;
	//return NULL;
}
int main(void)
{
	char str[] = "degh,odf;j,oi";
	const char delim[]=",;";
	char *p;
	/*fgets(str,sizeof(str),stdin)
	  str[strlen(str)] = '\0';
	  fgets(delim,sizeof(delim),stdin)
	  str[strlen(delim)] = '\0';*/
	printf("%s\n",mystrtok(str,delim));
	while(p =  mystrtok(NULL,delim))
		//printf("%s\n",mystrtok(NULL,delim));
		printf("%s\n",p);
	return 0;
}
