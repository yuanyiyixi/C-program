#include <stdio.h>

int main(void)
{
//	void *p = 100;
	int *t = 0x08048314;
	int a = 100;
	printf("0x%x\n",a);
	printf("%x\n",*(t));
	printf("%p\n",main);
	printf("0x%x\n",a+1);
//	printf("%p\n",p+1);
	printf("(int *)a = %p\n",(int *)a - 1);
	return 0;
}
