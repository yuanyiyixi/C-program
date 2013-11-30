#include <stdio.h>
#include <string.h>
int main ()
{
	int b=0,v[10];
	char a[10];
	int i = 0,flag = 0;
	int s = 0;
	scanf("%s",a);
	b = strlen(a);
	for(i=0;i<b;)
	{
		switch (a[i])
		{
			case '0': v[i] = 0; break;
			case '1': v[i] = 1; break;
			case '2': v[i] = 2; break;
			case '3': v[i] = 3; break;
			case '4': v[i] = 4; break;
			case '5': v[i] = 5; break;
			case '6': v[i] = 6; break;
			case '7': v[i] = 7; break;
			case '8': v[i] = 8; break;
			case '9': v[i] = 9; break;
			case 'A':case 'a': v[i] = 10; break;
			case 'B':case 'b': v[i] = 11; break;
			case 'C':case 'c': v[i] = 12; break;
			case 'D':case 'd': v[i] = 13; break;
			case 'E':case 'e': v[i] = 14; break;
			case 'F':case 'f': v[i] = 15; break;
			default : printf("输入非法字符，请重新输入："); 
			flag = -1; 
		}
		if (flag == -1) 
		{
			scanf("%s",a);
			flag = 0;
			b = strlen(a);
			i = 0;
			s = 0;
			continue;
		}
		s *= 16;
		s += v[i];
		i++;
	}
	printf ("%d\n",s);
	return 0;
}
