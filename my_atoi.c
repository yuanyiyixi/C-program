#include <stdio.h>
#include <string.h>
int main()
{
	char v[30];
	int s=0,i,n,k,a;
	scanf("%s",v);
	n=strlen(v)-1;		
	for (i=0;i<=n;i++)
	{
			a=v[i]-'0';
		k=n-i;
		for(;k>0;k--)
		{
			a=a*10;
		}
		s+=a;
	}
	printf("%d\n",s);
	return 0;
}
