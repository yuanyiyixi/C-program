#include <stdio.h>

int main (void)
{
	unsigned char c = 0xfc;
	unsigned int i = ~c;
	unsigned char a = 0xfb;
	unsigned int m = a & c;
	
	printf("%08x\n, %08x\n", i, m);
	int b = 21;
	int j = 56; 
	printf("%d\n%d\n",b & j,b && j);
	 
 int d = 0x80;
	 printf("%x\n",d>>1);
	 printf("%x\n",d<<1);

	return 0;
}
