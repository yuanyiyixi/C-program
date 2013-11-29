#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <sys/types.h>
#include <time.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <signal.h>
struct task_t
{
	int counter;
	int task;
	int num;
}iterm[5];
pthread_mutex_t counter_mutex = PTHREAD_MUTEX_INITIALIZER;

void do_sig(int signo)
{
	time_t t;
	int i;
	if(!pthread_mutex_trylock(&counter_mutex))
	{
		printf("the ID : 0x%x\n",(unsigned int)pthread_self());
		for (i = 0; i < 5; i++)
		{
			printf("the task : %d\t",iterm[i].task);
			printf("the num : %d\n",iterm[i].num);
		}
		time(&t);
		printf("%s\n",ctime(&t));
		pthread_mutex_unlock(&counter_mutex);
	}
}
void *foo(void *arg)
{
#if 1
	int *p = arg;

//	alarm(1);
	while(iterm[*p].task != 100)
	{
		iterm[*p].num++;
		iterm[*p].task = (100 * iterm[*p].num)/iterm[*p].counter;
		usleep(100);
	}
#endif
}
int main(void)
{
	pthread_t tid[5];
	int fd;
	int i;
	int count[5];

	fd = open("tem.log",O_RDWR | O_CREAT | O_TRUNC | O_APPEND, 0666);
	int save_fd = dup(STDOUT_FILENO);
	dup2(fd, STDOUT_FILENO);
	close(fd);

	struct sigaction newact;
	newact.sa_handler = do_sig;
	sigemptyset(&newact.sa_mask);
	newact.sa_flags = 0;
	sigaction(SIGALRM, &newact, NULL);
	for (i = 0; i < 5; i++)
	{
		iterm[i].counter = (i + 1) * 5000;
		iterm[i].task = 0;
		iterm[i].num = 0;
		count[i] = i;
		pthread_create(&tid[i], NULL, foo, (void *)&count[i]);
	}
	while(1)
	{
		int n = 0;
		for(i = 0; i < 5; i++)
		n += iterm[i].task;
		if (n == 500)
			break;
		alarm(1);
		sleep(1);
	}
	for (i = 0; i < 5; i++)
		pthread_join(tid[i], NULL);

	//dup2(save_fd, STDOUT_FILENO);
	return 0;
}

