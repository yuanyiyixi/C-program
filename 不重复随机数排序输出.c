#include <stdio.h>
int main (void)
{
	int v[100]={0};
	int i = 0,j =0;
	int t = 0;
	srand(time(NULL));
	for (i=0;i<100;i++)
	{
	x:v[i]=rand()%1000;
		for (j = 0;j<i;j++)		//有重复时重新获得随机数，并再次判断
			if (v[j] == v[i])  
				goto x;			//i --;break;
	}
	for(i=1;i<100;i++)			//随机数排序
	{
		for(j=0;j<100-i;j++)
		{
			if(v[j]>v[j+1])
			{
				t=v[j];
				v[j]=v[j+1];
				v[j+1]=t;
			}
		}
	}
	for(i=0;i<100;i++)			//输出随机数
		{printf ("%4d ",v[i]);
		if ((i + 1)%10==0)
			printf ("\n");
		}
	return 0;
}
