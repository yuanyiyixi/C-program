#include <stdio.h>
#define N	10
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
void merge(int a[], int l, int m, int r)
{
	int i, j, k, b[r+1];
	//for (i = 0; i <= r; i++)
	for (i = l; i <= r; i++)
		b[i] = a[i];
	i = l; 
	j = m + 1; 
	k = l;
	while (i <= m && j <= r)
		if(b[i] < b[j])
			a[k++] = b[i++];
		else 
			a[k++] = b[j++];
	while (i <= m)
		a[k++] = b[i++];
	while (j <= r)
		a[k++] = b[j++];
	return;
}
void merge_sort(int a[], int l, int r)
{
	if (l >= r)
		return;
	int m = (l + r)/2;
	merge_sort(a, l, m);
	merge_sort(a, m + 1, r);
	merge(a, l, m, r);
	return;
}
int main(void)
{
	int a[N];
	init_array(a, N);
	show(a, N);
	merge_sort(a, 0, N - 1);
	show(a, N);
	return 0;
}
