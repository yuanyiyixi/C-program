#include<stdio.h>
#include<string.h>
extern int foo(void);
int main()
{
#ifdef DEBUG
	printf("hello");
#endif
	foo();
	int a,b,c;
	a=10;
	b=19;
	c=32;
	c=a+b+c;
	printf("%d\n",c);
	return 0;
}
