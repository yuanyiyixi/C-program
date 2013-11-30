#include <stdio.h>

int count_bit_1_1(int num)
{
	int counter = 0;
	int i;

	for(i = 0;i < 8;i++)
		if(num & (1 << i))
			counter++;

	return counter;
}
int count_bit_1_2(int num)
{
	int count = 0;
	while(num)
	{
		num &= (num - 1);
		count++;
	}
	return count;
}
int count_bit_1_3(int num)
{
	num = (num & 0x55555555) + ((num >> 1) & 0x55555555);
	num = (num & 0x33333333) + ((num >> 2) & 0x33333333);
	num = (num & 0x0f0f0f0f) + ((num >> 4) & 0x0f0f0f0f);
	num = (num & 0x00ff00ff) + ((num >> 8) & 0x00ff00ff);
	num = (num & 0x0000ffff) + ((num >> 16) & 0x0000ffff);

	return num;
}
int main(void)
{
	int ret1 = 0, ret2 = 0,ret3 = 0;
	int i;

	printf("demo count bit 1:\n"); 
	for(i = 0; i <= 100; i++)
	{
		ret1 += count_bit_1_1(i);
		ret2 += count_bit_1_2(i);
		ret3 += count_bit_1_3(i);
	}
	printf ("100 has %d bit 1\n",ret1);
	printf ("100 has %d bit 1\n",ret2);
	printf ("100 has %d bit 1\n",ret3);

	return 0;
}
