#include <stdio.h>
#include <string.h>
void re(char str[],int l)
{
	int i,j = 1;
	char str1[50]={" "};
	int k = 0;
	for(i = 0; i < l; i++)
	{
		//for(j= 0;j<i;j++)
		while(str[i]==str[i + j])
		{
			str1[k]=str[i];
			j++;
		}
		i = i + j - 1;
		j = 1;
		k++;
	}
	for (i = 0;i<k;i++)
		for(j = 0;j < k; j++)
		{
			if(str[i] == str[j] && i != j)
				break;
			else 
			printf("%c ",str1[i]);
		}
}
int main (void)
{
	char str[100];
	char str1[50]={" "};
	int l;
	fgets(str,sizeof(str),stdin);
	l = strlen(str) - 1;
	re(str,l);
		return 0;
}
