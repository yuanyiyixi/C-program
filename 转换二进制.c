#include <stdio.h>
int main(void)
{
	int a,s=0,n;
	char str[100];
	scanf("%d",&a);
	do{
		n=a%2;
		a/=2;
		if(n==1) s++;
	}while(a!=0);
	printf("%d\n",s);
	return 0;
}
