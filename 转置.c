#include <stdio.h>
int main (void)
{
	int n[100][100]={0};
	int i,j,t;
	int a,b,c;								//a表示行，b表示列
	printf ("input the row and column:");	//输入数组的行和列数量
	scanf ("%d %d",&a,&b);
	for (i=0;i<a;i++)						//输入二位数组
		for(j=0;j<b;j++)
			scanf("%d",&n[i][j]);
	a>b?(c=a):(c=b);							//c存放a和b中的最大数
	for (i=0;i<c;i++)						//数组转置
	{
		for(j=0;j<i;j++)
		{
			t=n[i][j];
			n[i][j]=n[j][i];
			n[j][i]=t;
		}
	}
	for (i=0;i<b;i++)					//转置后行和列的数量交换
	{
		for(j=0;j<a;j++)
			printf ("%d\t",n[i][j]);
		printf ("\n");
	}
	return 0;
}
