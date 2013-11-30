/*测小端法*/

#include <stdio.h>
union 
{
	int a;
	short b[2];
}it;
int main (void)
{
 it.a=0x12345678;
	//scanf("%d",&it.a);
	printf ("%hx\t%hx\n",it.b[1],it.b[0]);
	return 0;
}
