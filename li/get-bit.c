#include <stdio.h>

int get_bit(int num,int pos)
{
	if( num & (1 << pos))
		return 1;
	else
		return 0;
}
int main(void)
{
	int num, pos;
	scanf("%d%d",&num,&pos);
	if(get_bit(num,pos))
		printf("%d is 1\n",pos);
	else printf("%d pos is 0\n",pos);
	return 0;
}
