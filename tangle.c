#include <stdio.h>
int main (void)
{
	int i,j,n,num;
	scanf ("%d",&i);
	for(j=0;j<i;j++)	//行数的控制
	{
		for (n=0;n<i-j-1;n++)	//每行*前的空格数
			printf (" ");
		for (num=0;num<=j;num++)	//每行输出*个数的控制
			printf ("* ");
		printf ("\n");
	}
	return 0;
}
