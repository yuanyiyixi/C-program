#include <stdio.h>

void put_oct(int num)
{
	char oct[8] = "01234567";
	putchar(oct[num]);
}
void put_int_oct(int num)
{
	int i;
	for(i = 10; i >= 0; i--)
		put_oct(((unsigned)num >> i*3) & 0x07);
}
int main(void)
{
int num;
	scanf("%d",&num);
	put_int_oct(num);
	printf("\n");
	return 0;
} 
