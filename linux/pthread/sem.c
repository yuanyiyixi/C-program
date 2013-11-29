#include <stdlib.h>
#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>

#define NUM	5
int queue[NUM];
sem_t blank_number, product_number;
	static int c = 0;
	static int p = 0;
void *producer(void *arg)
{
	while(1)
	{
		sem_wait(&blank_number);
		queue[p] = rand() % 1000;
		printf("producer %d\n",queue[p]);
		p = (p + 1) % NUM;
		sleep(rand() % 5);
		sem_post(&product_number);
	}
}
void *producer1(void *arg)
{
	while(1)
	{
		sem_wait(&blank_number);
		queue[p] = rand() % 1000;
		printf("producer1 %d\n",queue[p++]);
		//p = (p + 1) % NUM;
		p %= NUM;
		sleep(rand() % 5);
		sem_post(&product_number);
	}
}
void *consumer(void *arg)
{
	while(1)
		{
			sem_wait(&product_number);
			printf("consume %d\n",queue[c]);
			c = (c + 1) % NUM;
			sleep(rand() % 5);
			sem_post(&blank_number);
		}
}
void *consumer1(void *arg)
{
	while(1)
		{
			sem_wait(&product_number);
			//printf("consume1 %d\n",queue[c]);
			c = (c + 1) % NUM;
			sleep(rand() % 5);
			sem_post(&blank_number);
			printf("consume1 %d\n",queue[c]);
		}
}
int main(int argc, char *argv[])
{
	pthread_t pid, pid1, cid, cid1;
	srand(time(NULL));
	sem_init(&blank_number, 0, NUM);
	sem_init(&product_number, 0, 0);
	pthread_create(&pid, NULL, producer, NULL);
	pthread_create(&pid1, NULL, producer1, NULL);
	pthread_create(&cid, NULL, consumer, NULL);
	pthread_create(&cid1, NULL, consumer1, NULL);
	pthread_join(pid, NULL);
	pthread_join(cid, NULL);
	pthread_join(cid1, NULL);
	pthread_join(pid1, NULL);
	sem_destroy(&blank_number);
	sem_destroy(&product_number);
	return 0;
}

