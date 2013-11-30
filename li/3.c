#include <stdio.h>

void get_ch(void)
{
	char ch;
	system("stty raw");
	system("clear");
	do{
		ch = getchar();
		printf("ch = %c (ox%x)\n\r",ch,ch);
	}while(1);
	system("stty -raw");
}
int main(void)
{
	get_ch();
	return 0;
}
