#include <stdio.h>
int foo (int n)
{
	int s=1;
	if(n==0)s=1;
	else
	s = n*foo(n-1);
	return s;
}
int main(void)
{
	int n;
	n=	foo(5);
	printf("%d\n",n);
	return 0;
}
