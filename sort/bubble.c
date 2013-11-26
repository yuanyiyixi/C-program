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
void bubble_sort(int a[], int len)
{
	int i = 0, j = 0;
	for (i = 1; i < len; i++)
		for(j = 0; j < len - i; j++)
		{
			if(a[j] > a[j + 1])
				swap(&a[j], &a[j + 1]);
		}
}
int main(void)
{
	int a[N];
	init_array(a, N);
	bubble_sort(a, N);
	//show(a, N);
	return 0;
}
