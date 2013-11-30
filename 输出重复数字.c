#include <stdio.h>
int main (void)
{
	int i,j,b[10]={10};
	int k=0;
	char a[100];
	//long int  n=0;
	scanf("%s",a);				//输入一个整数
	for (i=0;a[i]!='\0';i++)
	{
		//a[i]=n%10;				//在数组中存入整数的每位数字
		//n/=10;
		for (j=0;j<i;j++)		//找出数组a中存入的相同数字
		{
			if(a[j]==a[i])
			{
				k=a[j]-'0';			//相同的数字赋给数组b,相同的数是几就存入b的第几个元素位置
				b[k]=k;
			}
		}
	}
	if (b[0]!=10) printf("%3d",b[0]);//输出数组b中不等于10的数字，即被重新赋值的数
	for (k=1;k<10;k++)			
		if (b[k]!=0) 
			printf("%3d",b[k]);
	printf ("\n");
	return 0;
}
