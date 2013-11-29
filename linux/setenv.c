#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
	char buf[4096];
	char *name;
	getcwd(buf,sizeof(buf));
	name = getenv("PATH");
	printf("PATH = %s\n", getenv("PATH"));

	strcat(name,":");
	strcat(name, buf);
	setenv("PATH",name,1);
	printf("PATH = %s\n", getenv("PATH"));
	unsetenv("PATH");
	printf("PATH = %s\n", getenv("PATH"));
	return 0;
}
