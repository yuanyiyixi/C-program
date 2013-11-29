#include <unistd.h>
#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

struct ITERM {
	int sec;
	char buf[100];
}iterm_t[2] = {{1,"AAAAAAAAA\n"}, {2, "BBBBBBBBB\n"}};

void *thr_fn(void *arg)
{
	struct ITERM *p = arg; 
	while(1)
	{
		//	printf("%s", p->buf);
		//	sleep(p->sec);
		pthread_testcancel();
	}
	//pthread_exit((void *)2);
}

int main(void)
{
	pthread_t tid[2];

	pthread_create(&tid[0], NULL, thr_fn, (void *) &iterm_t[0]);
	pthread_create(&tid[1], NULL, thr_fn, (void *) &iterm_t[1]);
	sleep(10);
	pthread_cancel(tid[0]);
	pthread_cancel(tid[1]);
	while(1);
	return 0;
}
