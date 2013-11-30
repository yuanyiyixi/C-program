#include <stdio.h>
/*int foo(int n,int i)
{
	if(i==0) n=1;
	else 
	{
		n*=2;
		i--;
	}
	return n;
}*/
int main()
{
	int a,n,s=0,i=0,j;
	scanf("%d",&a);
	do{
		n=a%10;
		j=i;
		for(;i>=0;i--)
		{
			n*=2;
		s+=n;
		}
		j++;
		a=a/10;
	}while(!a);
	printf("%d\n",s);
	return 0;
}
