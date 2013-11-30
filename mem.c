#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	int i;
	char *q;
	char *p = malloc(1);
	*p = 'a';
	for(i = 1; i <= 10; i++)
	{
		p = realloc(p,i + 1);
	* (p + i) = * (p + i - 1) + 1;
	//puts(buf);
	}
	p = realloc(p,i);
	*(p + i) = '\0';
	printf(p);
	free(p);
	//puts(buf);
	return 0;
}
