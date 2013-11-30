#include <stdio.h>
float op(int  a,int b)
{
	float n;
	n = (a + b)/2;
	return n;
}
int main (void)
{
	float n;
	int a,b;
	scanf ("%d%d",&a,&b);
	 n= op(a,b);
	 printf ("%.2f\n",n);
	 return 0;
}
