#include <stdio.h>
#include <string.h>
int len (char str[],int k)
{
	int n=0;
	if(str[k]=='\0') return strlen(str);
	else
	{
	for(;str[k]!=' '&&str[k]!='\n';k++)
		n++;
	 if(n>len(str,k+1)||n==0) n=len(str,k+1);	
	return n;
	}
}
int main (void)
{
	char str[100];
	int l;
	fgets(str,sizeof(str),stdin);
	l = len(str,0);
	printf("%d\n",l);
	return 0;
}
