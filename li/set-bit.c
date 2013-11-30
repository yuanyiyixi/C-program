#include <stdio.h>

void set_bit(int num, int pos, int value)
{
	if (value == 1)
	num |= (1 << pos);
	else num &= ~(1 << pos);
	printf("%x\n",num);
}
int main(void)
{
	int num, pos, value;
	scanf("%d%d%d",&num,&pos,&value);
	set_bit(num,pos,value);
	return 0;
}
