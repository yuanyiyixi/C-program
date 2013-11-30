#include <stdio.h>

void n_n(int a, int b,int c)
{
	int i, n = 0,j;
	for (j = a; j <= b; j++)
	{
		i = j;
		do
		{
			if(i%10 == c)
			{
				n++;
			}
			i /= 10;
		}while(i != 0);
	}
	printf("%d\n",n);
	return ;
}
int main(void)
{
	int a, b, c;
	scanf("%d%d%d",&a,&b,&c);
	n_n(a,b,c);
	return 0;
}
