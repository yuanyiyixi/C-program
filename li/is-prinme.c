#include <stdio.h>
#include <math.h>
//判断是否为质数
int is_prime(int num)
{
	int i;
	if(num == 1 || num == 0) return 0;
	for(i = 2; i <= num/2; i++)
		if(num % i == 0)
			return 0;
	return 1;
}
int is_prime_1(int num)
{
	int i;
	if(num == 1 || num == 0) return 0;
	for(i = 2; i <= sqrt(num); i++)
		if(num % i == 0)
			return 0;
	return 1;
}
void arry(int a[],int num)
{
	int i;
	for(i = 0; a[i] <= sqrt(num) ; i++)
		if(num % a[i] == 0)
			return ;
	for(i = 0; a[i] != 0 ; i++);
		a[i] = num;
	return ;
}
int is_prime_2(int num,int a[])
{
	int i;
	if(num == 1 ) return 0;
	else if(num == 2) return 1;

	for(i = 3; i <= sqrt(num); i++)
		arry(a,i);
	//for( i = 0; a[i] <= sqrt(num); i++)
	for( i = 0; a[i] != 0; i++)
		if(num % a[i] == 0) 
			return 0;
	return 1;
}
int main(void)
{
	int num = 0, i;
	scanf("%d",&num);
	int a[100]={2};
#if 0
	if (is_prime(num))
		printf("YES\n");
	else printf("NO\n");

	if (is_prime_1(num))
		printf("YES\n");
	else printf("NO\n");

#endif
	if (is_prime_2(num,a))
		printf("YES\n");
	else printf("NO\n");

	for( i = 0; a[i] != 0; i++)
		printf("%3d", a[i]);
	return 0;
}
