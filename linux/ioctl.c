#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/ioctl.h>

int main(void)
{
	struct winsize size;
	if(isatty(STDOUT_FILENO) == 0)
		exit(1);
		if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &size) < 0)
		{
			perror("icotl TIOCGWINSZ error");
			exit(1);
		}
		printf("%d rows, %d colums\n", size.ws_row, size.ws_col);
	return 0;
}

