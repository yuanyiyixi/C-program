#include <stdio.h>
int main (void)
{
	int year,month,day;
	int days=0;
	int i;
	scanf ("%d %d %d",&year,&month,&day);
	int t[12]={31,0,31,30,31,30,31,31,30,31,30,31};
	if ((year%100 != 0 || year%400 == 0)&&(year%4 == 0)) t[1] = 29;
	else t[1] = 28;
	for (i=0;i<month-1;i++)
		days += t[i];
	days += day;
	printf ("%d\n",days);
	return 0;
}
