#include <stdio.h>
int main (void)
{
	int max(int*,int);
	int a[3]={3,5,4};
	int b;
	b=max(a,3);
	/*
	   int a[100];
	   for(i=0;a[i]!='\n';i++)
	   scanf("%d",a[i]);
	   b=max(a,i);
	 */
	printf("%d\n",b);
	return 0;
}
int max(int a[],int n)
{
	int i;int max;
	max=a[0];
	for(i=0;i<n;i++)
	{
		if(a[i]>max)
			max=a[i];
	}
	return max;
}
