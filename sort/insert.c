#include <stdio.h>
#define N	1000000
#define MAX 1000000
void init_array(int a[], int len)
{
	int i = 0;
	srand(time(NULL));
	for (i = 0; i < len; i++)
		a[i] = rand() % MAX;
	return;
}
void show(int a[], int len)
{
	int i = 0;
	for (i = 0; i < len; i++)
		printf("%5d",a[i]);
	printf("\n");
	return;
}
void insert_sort(int a[], int len)
{
	int i = 0, j = 0 , tmp = 0;
	for (i = 0; i < len; i++)
	{
		tmp = a[i + 1];
		for (j = i; tmp < a[j] && j >= 0; j--)
			a[j + 1] = a[j];
		a[j + 1] = tmp;
	}
}
int main(void)
{
	int a[N];
	init_array(a, N);
	//show(a, N);
	insert_sort(a, N);
	//show(a, N);
	return 0;
}
