#include <stdio.h>
del_space(char *str)
{

}

int main(void)
{
	char buf[64];
	printf("demo argc argv\n");
	while(1)
	{
	printf("myshell$$");
	fgets(buf,sizeof(buf),stdin);
	buf[strlen(buf) - 1] = '\0';

	printf("buf = <%s>\n",buf);
	del_space(buf);
	}
}
