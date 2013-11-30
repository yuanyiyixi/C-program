#include <stdio.h>
int main (void)
{
	int i,j,k;
	char str[100];

	//input a integer
	printf("Please input a integer");
	scanf("%d",&i);
	printf("%d\n",i);

	//input some integers
	printf("Please input 3 integers:");
	scanf("%d %d %d",&i,&j,&k);
	printf("i = %d,j = %d,k = %d\n",i,j,k);

	//input a string
	printf("Please input a string");
	scanf("%s",str);
	printf("%s\n",str);

	return 0;
}
