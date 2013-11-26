#include <stdio.h>
#include <stdlib.h>
#define N	100
#define MAX 100
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
int search(int a[], int l, int r, int key)
{
	while (l <= r)
	{
	int m = (l + r)/2;
	if(key > a[m])
		l = m + 1;
	else if(key < a[m]) 
		r = m - 1;
	else return 1;
	}
	return 0;
}
int search_r(int a[], int l, int r, int key)
{
	if(l > r) return 0;
	int m = (l + r)/2;
	if(key < a[m])
		return search_r(a, l, m - 1, key);
	else if(key > a[m])
		return search_r(a, m + 1, r, key);
	else return 1;
}
int main(int argc, char *argv[])
{
	int a[N],key;
	key = atoi(argv[1]);
	init_array(a, N);
	bubble_sort(a, N);
	//if(search(a, 0, N - 1, key))
	if(search_r(a, 0, N - 1, key))
		printf("OK!\n");
		else printf("NO!\n");
	show(a, N);
	return 0;
}
