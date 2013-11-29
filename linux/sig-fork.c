#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

static pid_t pid;

void do_sig(int num)
{
	if (pid > 0)
	{
		static int	m = 1;
		printf("I am %d\t %d\n", getpid(),m);
		m += 2;
		kill(pid,10);
	}
	else 
	{
		static int	n;
		printf("I am %d\t %d\n", getpid(),n);
		n += 2;
		kill(getppid(),10);
	}
	sleep(1);
}

int main(void)
{
	int n = 0;
	struct sigaction act, oact;

	act.sa_handler = do_sig;
	sigemptyset(&act.sa_mask);
	act.sa_flags = 0;
	sigaction(SIGUSR1, &act, &oact);

	pid = fork();
	if (pid < 0)
	{
		perror("fork");
		exit(-1);
	}
	else if(pid > 0)
		kill(pid,10);

	while(1)	;

	wait(NULL);
	return 0;
}
