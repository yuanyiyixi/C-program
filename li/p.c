#include <stdio.h>

void say_hello(char *str)
{
	printf("hello,%s\n",str);
	return;
}

typedef	void (*F)(char *);
typedef	void FF(char *);

int main(void)
{
	void (*f)( char *);
	int a;
	F f2;
	FF * f3;

	f = say_hello;
	f2 = say_hello;
	f3 = say_hello;

	printf("f = %p\n",f);
	printf("say_hello = %p\n",say_hello);

	//a = 0x80483e4;//修改地址，其他地址,函数入口地址，跳转指令
	a = 0x8048300;//修改地址，其他地址,函数入口地址，跳转指令
	((void (*) (char *))a)("dindin");

	((F)0x80483e4)("lala");
	((FF *)0x80483e4)("po");

	f("dici");
	f2("lily");
	f3("lucy");

	return 0;
}
