#include <stdio.h>

int main()
{
	int mon,day,year;
	int flag;
	scanf("%d/%d/%d",&mon,&day,&year);
	if(mon>12&&mon<=0)  flag=0;
	else if(mon==2)
	{
		if((year%100!=0&&year%4==0)||(year%400==0))
		{	if(day>29&&day<=0)  flag=0;
		else flag=1;}
		else{ if(day>28&&day<=0)  flag=0;
		else flag = 1;}
	}
	else flag = 1;
	if(flag==1)	printf("%04d%02d%02d",year,mon,day);
	else printf("输入日期不正确");
	return 0;
}
