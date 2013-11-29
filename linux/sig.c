#include <signal.h>
#include <stdio.h>

void printsigset(const sigset_t *set)
{
	int i;
	for (i = 0; i < 32; i++)
		if (sigismember(set, i) == 1)
			putchar('1');
		else 
			putchar('0');
	puts("");
}
int main(void)
{
	sigset_t s, p;
	sigemptyset(&s);
	sigaddset(&s, SIGINT);
	sigprocmask(SIG_BLOCK, &s, NULL);
	int n = 10;
	while(n--)
	{
		sigpending(&p);
		printsigset(&p);
		sleep(1);
	}
	sigemptyset(&s);
	sigdelset(&s, SIGINT);
	sigprocmask(SIG_UNBLOCK, &s, NULL);
	while(n--)
	{
		sigpending(&p);
		printsigset(&p);
		sleep(1);
	}
	return 0;
}
