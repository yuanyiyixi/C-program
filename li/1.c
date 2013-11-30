#include <stdio.h>
#include <string.h>

int main(void)
{
	char *p = NULL;
	char str[10];
	p = str;
	p = "string";
	strcpy(str,"hello");
	printf("p = %c\n",*p);
	printf("str[] = %s\n",str);
	printf(0x8048114+'\n');

	return 0;
}
