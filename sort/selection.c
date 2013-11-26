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
void swap(int *a, int *b)
{
	int t;
	t = *a;
	*a = *b;
	*b = t;
}
void select_sort(int a[], int len)
{
	int i = 0, j = 0, min = 0;
	for (i = 0; i < len; i++)
	{
		min = i;
		for(j = i + 1; j < len; j++)
			if(a[min] > a[j])
				min = j;
		swap(&a[min], &a[i]);
	}
	return;
}
int main(void)
{
	int a[N];
	init_array(a, N);
	select_sort(a, N);
	//show(a, N);
	return 0;
}
