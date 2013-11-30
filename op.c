#include<stdio.h>

int sub(int a,int b)
{
	int res;
	res = a - b;
	return res;
}
int add(int a,int b)
{
	int res;
	res = a + b;
	return res;
}
int s(int a,int b)
{
	int res;
	res = a * b;
	return res;
}
float dev(int a,int b)
{
	float res;
	res = a/b;
	return res;
}
int main()
{
	int a;
	int b;
	int res1;
	int res2;
	int res3;
	float res4;
	scanf("%d%d",&a,&b);
	res1 = sub(a,b);
	res2 = add(a,b);
	res3 = s(a,b);
	res4 = dev(a,b);
	printf("%d - %d = %d\n",a,b,res1);
	printf("%d + %d = %d\n",a,b,res2);
	printf("%d * %d = %d\n",a,b,res3);
	printf("%d / %d = %.2f\n",a,b,res4);
	return 0;
}
