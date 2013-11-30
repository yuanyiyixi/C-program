#include<stdio.h>

int main(void)
{
	int i,s,j,t;
	int a,b;
	int n,count=0;
	int v[100];
	printf("输入产生随机数的个数");
	scanf("%d",&s);
	printf("输入随机数的范围a,b(a<b)");
	scanf("%d%d",&a,&b);
	printf("输入要求输出组合的总和");
	scanf("%d",&n);
	srand(time(NULL));
	for(i=0;i<s;i++)			//产生随机数
	{
		v[i]=a + rand()%(b-a);
	}
	for(i=1;i<s;i++)			//随机数排序
	{
		for(j=0;j<s-i;j++)
		{
			if(v[j]<v[j+1])
			{
				t=v[j];
				v[j]=v[j+1];
				v[j+1]=t;
			}
		}
	}
	for(i=0;i<s;i++)			//输出随机数
		printf("%d\n",v[i]);
	for(i=0;i<s;i++)			//输出和为n的组合
	{
		for(j=i+1;j<s;j++)
		{
			if(	v[i]+v[j]==n)	
			{
				printf("v[%d]=%d,v[%d]=%d\n",i,v[i],j,v[j]);
				count ++;
			}
			else if(v[i]+v[j]<n) 
			{
				for(t=j+1;t<s;t++)
					if(v[i]+v[j]+v[t]==n) 
					{
						printf("v[%d]=%d,v[%d]=%d,v[%d]=%d\n",i,v[i],j,v[j],t,v[t]);
						count ++;
					}
			}
		}
	}
	if(count==0) printf("没有找到该组合\n");
	return 0;
}
