#include <stdio.h>
int main (void)
{
	int a[100],b[2][10]={0,1,2,3,4,5,6,7,8,9};
	int n;
	int i = 0;
	scanf ("%d",&n);
	for (i=0;n!=0;i++)
	{
		a[i] = n % 10;
		n /= 10;
		b[1][a[i]]++;
	}
	printf ("digit:       ");
	for (i=0;i<10;i++)
		printf ("%3d",b[0][i]);
	printf ("\n");
	printf ("occurrences: ");
	for (i=0;i<10;i++)
		printf ("%3d",b[1][i]);
	printf ("\n");
	return 0;
}
