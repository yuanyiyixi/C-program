#include <stdio.h>
int  sum(int a,...)
{
	int s = 0;
	int *p = &a;
	while(*p != 0)
	{
		s += *p;
		p++;
	}
	return s;
}
int main(void)
{
	int a = 10;
	int b = 20;
	int s = 0;
	s = sum(a,b,0);
	printf("%d\n",s);
	s = sum(12,13,14,0);
	printf("%d\n",s);
	return 0;
}
