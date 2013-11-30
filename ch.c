#include <stdio.h>
#include <string.h>
int ch_h ( char str[],char ch,int l)
{
	int i;
	for (i = 0;i<l;i++)
	{
		if (str[i]==ch)
			return 1;
		else return 0;
	}
}
int main (void)
{
	char str[100];
	int l, n;
	fgets(str,sizeof(str),stdin);
	l = strlen(str) - 1;
	n = ch_h(str,'h',l);
	if (n)
		printf ("YES\n");
	else printf ("NO\n");
	return 0;
}
