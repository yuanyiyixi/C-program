#include <stdio.h>

int main(void)
{
	char buf[11];
	fgets(buf, 10, stdin);
	printf("%s", buf);
	return 0;
}
