#include <stdio.h>
#include <time.h>

#define N	100	
#define MAX 100	
void init_array(int a[], int len)
{
	int i, j;
	srand(time(NULL));
	for (i = 0; i < len; i++)
	{
		a[i] = rand() % MAX;
		for(j = 0; j < i; j++)
			if(a[j] == a[i])
			{
				i--;
				break;
			}
	}
}
void show(int a[], int len)
{
	int i = 0;
	for (i = 0; i < len; i++)
		printf("%3d",a[i]);
	printf("\n");
	return;
}
void sort(int a[], int len)
{
	char bit[MAX/8 + 1] = {0};
	int pos = 0, i = 0, j = 0;
	for (i = 0; i < len; i++)
		bit[a[i]/8] |= (1<< (a[i]%8));
	for(i = 0; i <= MAX/8; i++) 
	{
		for(pos = 0; pos < 8; pos++)
			if(bit[i] & (1 << pos))
			{
				a[j] = i*8 + pos;
				j++;
			}
	}
}
int main(void)
{
	int a[N];
	init_array(a, N);
	sort(a, N);
	show(a, N);
	return 0;
}
