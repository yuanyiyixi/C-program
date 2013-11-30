#include<stdio.h>

int main(void)
{
	double x,y;
	char op;
	scanf("%lf",&x);
	while((op=getchar())!='\n')
	{
		switch(op)
		{
			case '+':
				scanf("%lf",&y);
				x+=y;break;
			case '-':
				scanf("%lf",&y);
				x-=y;break;
			case '*':
				scanf("%lf",&y);
				x*=y;break;
			case '/':
				do{	scanf("%lf",&y);
					if(y==0)
						printf("除数不能为0，请重新输入除数");
					else {x/=y; break;}
				}while(1);
				break;
			default:printf("输入字符非法,本次输入无效");
					scanf("%lf",&x);break;
		}
	}
	printf("%lf\n",x);
	return 0;
}
