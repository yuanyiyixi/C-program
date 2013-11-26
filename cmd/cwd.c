#include <stdio.h>
#include <unistd.h>

int main(void)
{
	char buf[4096];
	getcwd(buf, sizeof(buf));
	printf("%s\n",buf);
	chdir("c");
	getcwd(buf, sizeof(buf));
	printf("%s\n", buf);
	return 0;
}
