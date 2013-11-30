#include <stdio.h>

int check(int str[][10],int a,int b)
{
	if (str[a][b]== 0)
		return 1;
		else return 0;
}
int main (void)
{
	int str[10][10]={0};
	int a,b;
	scanf("%d%d",&a,&b);
	if(check(str,a,b))
		printf ("YES\n");
		else printf ("NO\n");
		return 0;
}
