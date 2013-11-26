#include <stdio.h>

struct 
{
	int num;
	int flag;
}link[10000000];

int Josephus(int n,int m)
{
	int i,j,k;
	for (i = 0; i < n - 1; i++)
	{
		link[i].num = i + 1;
		link[i].flag = 1;
	}
	link[n - 1].num = 0;//最后一个人报数后，轮到第一个人报数
	link[n - 1].flag = 1;
	j = n - 1;
	for(i = 0; i < n; i++)//i表示死的人的个数
	{
		for(k = 0; k < m; k += link[j].flag)
				j = link[j].num;
		link[j].flag = 0;
	}
	
	return j + 1;
}
int main(void)
{
	int a,b,latter;
	scanf("%d%d",&a,&b);
	latter = Josephus(a,b);
	printf("%d\n",latter);
	return 0;
}
