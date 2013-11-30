#include <stdio.h>
#include <string.h>

void nu(char str[],int l)
{
	int i;
	for (i= 0;i < l; i++)
		if (str[i] == ' '||str[i]=='\0')
			break;
			printf ("%d\n",i);
			return ;
}
int main (void)
{
	char str[100];int l;
	fgets(str,sizeof(str),stdin);
	l = strlen(str)+1;
	nu(str,l);
	return 0;
}
