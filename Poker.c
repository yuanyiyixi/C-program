#include <stdio.h>
int main (void)
{
	int a[54];
	int i,j;
	a[0]=srand(time(NULL));
	for (i=1;i<54;i++)
	{
		a[i]=rand()%54;
		for(j=0;j<i;j++)
			if(a[j]==a[i])
			{
				i--;
				break;
			}
	}
	printf ("A\t\tB\t\tC\n");
	for(i=0;i<54;i++)
	{
		if(a[i]/13 == 0	)		
				printf("CLUBS:%3d\t",a[i]%13+1);
		else if (a[i]/13 ==1)
				printf("DIAMONDS:%3d\t",a[i]%13+1);
		else if(a[i]/13 == 2)
			printf ("HEARTS:%3d\t",a[i]%13+1);
		else if(a[i]/13 == 3)printf("SPADES:%3d\t",a[i]%13+1);
		else{ 
			if(a[i]==52)
				printf("Kinglet\t\t");
			else 
				printf("King\t\t");
		}
		if((i+1)%3==0) printf ("\n");
	}
	return 0;
}
