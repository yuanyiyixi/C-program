#include <stdlib.h>

void parse(char *buf, int *argc, char *argv[])
{
	char *p = buf;
	*argc = 0;
	int flag = 0;

	while(*p)
	{
		if(flag == 0 && (*p != ' ' && *p != '\n'))
		{
			argv[*argc] = p;
			(*argc)++;
			flag = 1;
		}
		else 
			if(flag == 1 && (*p == ' ' || *p == '\n'))
			{
				*p = '\0';
				flag = 0;
			}
			p++;
	}
	argv[*argc] = NULL;
	return;
}
