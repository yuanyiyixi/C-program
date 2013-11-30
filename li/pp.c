#include <stdio.h>

int gloable = 200;
const int myconst[100] = {300};
static int mystatic = 400;

int main (void)
{
	int local = 100;

	printf ("gloable = %p\n",&gloable);
	printf ("local = %p\n",&local);
	printf("myconst = %p\n",&myconst);
	printf("const string = %p\n","hello");
	printf ("mystatic = %p\n",&mystatic);
	printf ("main = %p\n",main);
	while(1);
	return 0;
}
