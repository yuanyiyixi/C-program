#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

pthread_mutex_t chop_mutex[5];
void *doit(void *vptr)
{
	int *i,a,b;
	i = vptr;
	while(1)
	{
		pthread_mutex_lock(&chop_mutex[(*i + 4) % 5]);

		printf("Philosopher %c fetches chopstick %d\n", *i + 'A',(*i + 4) % 5);
		if (!pthread_mutex_trylock(&chop_mutex[*i]))
		{
			printf("Philosopher %c fetches chopstick %d\n", *i + 'A',*i);
			sleep(rand() % 10);
			printf("Philosopher %c releases chopsticks %d %d\n", *i + 'A',*i, (*i + 4) % 5);
			pthread_mutex_unlock(&chop_mutex[(*i + 4) % 5]);
			pthread_mutex_unlock(&chop_mutex[*i]); 
			return NULL;
		}
		else
		{
			pthread_mutex_unlock(&chop_mutex[(*i + 4) % 5]); 
			sleep(rand() % 10);
		}
	}
}
int main(void)
{
	int i = 0;
	pthread_t tid[5];
	srand(time(NULL));
	int count[5];

	for (i = 0; i < 5; i++)
		pthread_mutex_init(&chop_mutex[i], NULL);

	for (i = 0; i < 5; i++)
	{
		count[i] = i;
		pthread_create(&tid[i], NULL, &doit, (void *)&count[i]);
	}

	for (i = 0; i < 5; i++)
		pthread_join(tid[i], NULL);

	return 0;
}
