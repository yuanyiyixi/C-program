#include <stdio.h>
#include <signal.h>

void do_sig(int num)
{
	int i = 5;
	while(i--)
	{
	printf("hello\n");
		sleep(1);
	}
}
#if 0
void do_sig1(void)
{
	printf("akaedu\n");
}
#endif

int main(void)
{
	struct sigaction act, oact;
	struct sigaction act1, oact1;

	act.sa_handler = do_sig;
	sigemptyset(&act.sa_mask);
	sigaddset(&act.sa_mask, SIGQUIT);
	act.sa_flags = 0;
	sigaction(SIGINT, &act, &oact);

	while(1)
	{
		printf("123\n");
		sleep(1);
	}
	sigaction(SIGINT, &oact, &act);
	return 0;
}
