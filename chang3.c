#include <stdio.h>
int main()
{
	int a,i,n;
	char v[100];
	char b[100];
	scanf("%d",&a);
	while(a)
	{
		if(a%16>9)
			v[i]=a%16-10+'A';
		else
			v[i]='0'+a%16;
		a/=16;
		i++;
	}
	n=--i;
	for(;i>=0;i--)
		b[n-i]=v[i];
	b[n+1]='\0';
	printf("%s\n",b);
	return 0;
}
