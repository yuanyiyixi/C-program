#include <stdio.h>
void rt (char a[],char b[])
{
	for(i = 0;i < strlen(a)- strlen(b);i++)
	{
		for(j = 0;j<strlen(b);j++)
			if(a[i+j] != b[j])
				break;
			else {
				n = i;
				m ++;
			}
			if (m == strlen(b))
	a[i+strlen(b)]='\0';
	}
}
int main (void)
{
	char a[20],b[10];
	fgets(a,sizeof(a),stdin);
	fgets(b,sizeof(b),stdin);
	rt(a,b,c);
}
