#include <stdio.h>

void set_bit_filed(int num,int pos,int len,int value)
{
	int i, s = 1;
	for(i = 0;i < len; i++)
		s *= 2;
		s--;
	num = num & (~(s << pos));
	num = num |(value << pos);
	printf("%x\n",num);
	return ;
}
int main(void)
{
	int num,pos,len,value;
	scanf("%d%d%d%d",&num,&pos,&len,&value);
	set_bit_filed(num,pos,len,value);
	return 0;
}
