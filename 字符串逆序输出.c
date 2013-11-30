#include <stdio.h>
#include <string.h>
void foo(char str[],int l)
{
	int i;
	char t;
	for(i=0;i<=l/2;i++)
	{
		t=str[i];
		str[i]=str[l-i];
		str[l-i]=t;
	}
	printf("%s\n",str);
	return ;
}
int main (void)
{
	char str[100];
	int l;
	fgets(str,sizeof(str),stdin);
	l=strlen(str);
	l--;
	foo(str,l);
	return 0;
}
