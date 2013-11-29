#include <unistd.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
	char buf[24];
	int len;
	printf("%s\n", ttyname(STDIN_FILENO));
	len = ttyname_r(STDIN_FILENO, buf, sizeof(buf));
	if(!len)
	{
		printf("len = %d\t%s\n",len, buf);
		write(1, buf, strlen(buf));
	}
	return 0;
}
