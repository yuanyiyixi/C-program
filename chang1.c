#include <stdio.h>
int main()
{
	int a,v[100];
	int i=0;
	scanf("%d",&a);
	do{
		v[i]=a%2;
		a=a/2;
		i++;
	}while(a!=0);
	for(--i;i>=0;i--)
		printf("%d",v[i]);
	return 0;
}
