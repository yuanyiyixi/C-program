#include <stdio.h>
#include <string.h>
int ch_h ( char str[],char ch,int n)
{
	int m = 0,l,i;
	l = strlen(str);
	for (i = 0;i<l;i++)
		if (str[i]==ch)
			m++;
	if (m == n)
	return 1;
	else return 0;
}
int main (void)
{
char str[100];	
fgets(str,sizeof(str),stdin);
if(ch_h(str,'x',5))
	printf("YES\n");
	else printf("NO\n");
	return 0;
}
