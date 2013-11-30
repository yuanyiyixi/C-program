#include <stdio.h>
int main (void)
{
	int i,j,n,num;
	scanf ("%d",&i);
	for(j=0;j<i;j++)	//菱形上边的三角形画出
	{
		for (n=0;n<i-j-1;n++)
			printf (" ");
		for (num=0;num<=j;num++)
			printf ("* ");
		printf ("\n");
	}
	for (j=i-1;j>0;j--)	//下三角总行数为i-1
	{
		for (n=0;n<i-j;n++)//每行空格数为输入数减去*的个数
			printf (" ");
		for (num=0;num<j;num++)
			printf ("* ");
		printf ("\n");
	}
	return 0;
}
