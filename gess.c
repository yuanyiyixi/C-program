#include <stdio.h>
#include <string.h>
int i=0,j=0;
void num(char a[])
{
	srand(time(NULL));
	for (i=0;i<4;i++)
	{
		a[i]=rand()%10 + '0';
		for(j=0;j<i;j++)
			if(a[j]==a[i])
			{
				i--;
				break;
			}
	}
	return ;
}
void enter(char b[],int c)
{
	int l=0;
x: printf("Please input four different letters:\n");
   fgets(b,c,stdin);
   l=strlen(b)-1;
   if(l!=4)
   {
	   printf("Invalid input\n");
	   goto x;
   }
   else 
   {
	   for(i=0;i<4;i++)
	   {
		   if(b[i]>='0'&&b[i]<='9')
		   {
			   for(j=0;j<i;j++)
				   if(b[j]==b[i])
				   {
					   printf("Invalid input\n");
					   goto x;
				   }
		   }
		   else 
		   {
			   printf("Invalid input\n");
			   goto x;
		   }
	   }
   }
   return ;
}
int compare(char a[],char b[])
{
	int n=0,m=0;
	for (i=0;i<4;i++)
		for(j=0;j<4;j++)
		{
			if(a[i]==b[j]&&i==j)
				n++;
			else if(a[i]==b[j]&&i!=j)
				m++;
		}
	if(n+m==0)
		printf("0000");
	else
	{
		for(i=0;i<n;i++)
			printf("A");
		for(i=0;i<m;i++)
			printf("B");
	}
	printf ("\n");
	return n;
}
int main (void)
{
	int n=0,m=0;
	char a[4];
	char b[20];
	num(a);
	while (n!=4)
	{
		enter(b,20);
		n=compare(a,b);
		m++;
		if(m==15)
		{
			printf("YOU FAILT\n");
			return 0;
		}
	}
	printf ("YOU BET!\n");
	return 0;
}
