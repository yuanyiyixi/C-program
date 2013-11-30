/*输出的数组中最大值和最小值，及其坐标位置*/
#include <stdio.h>
int main (void)
{
	int a[30];
	char ch;
	int k = 0,j = 0,i,t;
	int max,min;
	for (i=0;ch!='\n';i++)
	{	scanf ("%d",&a[i]);
		scanf ("%c",&ch);}
	max = a[0];
	min = a[0];
	for (t=1;t<i;t++)
	{
		if(a[t]>max)
		{
			max = a[t];
			k=t;
		}
		if (a[t]<min)
		{
			min = a[t];
			j=t;
		}
	}
	printf ("max is %d,coordinate is %d\n",max,k);
	printf ("min is %d,coordinate is %d\n",min,j);
	return 0;
}
