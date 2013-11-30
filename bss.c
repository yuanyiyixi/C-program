#include <stdio.h>
#define OFFSET(m) printf(#m " =  %p\n",&(((struct test *)0) -> m))
int main(void)
{
struct test{
	char a;
	short b;
	int c;
	char d; 
}s;
const int c;
short d = 12;
printf(" sizeof(s) = %d\n",sizeof(s));
printf(" sizeof(s) = 0x%x\n",d);
printf(" sizeof(d) = %d\n",sizeof(d));
OFFSET(a);
OFFSET(b);
OFFSET(c);
OFFSET(d);
//printf(" b = 0x%p\n",b);
return 0;
}
