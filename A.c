#include <stdio.h>
#include <string.h>

int main(void)
{
	char str[30];
	int i,max,n,j=0;
	int k;
	scanf("%s",str);
	n = strlen(str)-1;
	for (j=0;j<=n;j++)
	{
	max = str[j];
		for (i=j;i<=n;i++)
		{
			if (str[i]>=max)
			{
				max=str[i];
				k=i;
			}
		}
		for (i=k;i>=0;i--)
			str[i]=str[i-1];
		str[j]=max;
	}
	printf("%s\n",str);
	return 0;
}
