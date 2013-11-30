#include <stdio.h>
int sum (int n)
{
	if(n==1) return 1;
	else return n+sum(n-1);
}
int main (void)
{
	int s;
	s = sum(100);
	printf ("%d\n",s);
	return 0;
}
