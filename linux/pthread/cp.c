#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define N	4096
int fd1, fd2, m;
int size;
int n = 5;
int count[300];
struct ITERM{
	int len;
	int offset;
	int no;
};
void *thr_fn(void *arg)
{
	char *p1, *p2;
	struct ITERM *p = arg;
	int j, i = 1;

	for(i = 1; i <= (p->len / N); i++)
	{
		p1 = mmap(NULL, N, PROT_READ, MAP_PRIVATE, fd1, p->offset + (i - 1) * N);
		p2 = mmap(NULL, N, PROT_WRITE, MAP_SHARED, fd2, p->offset + (i - 1) * N);
		if (p1 == MAP_FAILED || p2 == MAP_FAILED)
		{
			perror("mmap");
			exit(-1);
		}
		for(j = 0; j < N; j++)
		{
			p2[j] = p1[j];
			count[p->no]++ ;
			usleep(1000);
		}
		munmap(p1, N);
		munmap(p2, N);
	}
	if (p->len % N)
	{
		p1 = mmap(NULL, p->len % N, PROT_READ, MAP_PRIVATE, fd1, p->offset + (i - 1) * N);
		p2 = mmap(NULL, p->len % N, PROT_WRITE, MAP_SHARED, fd2, p->offset + (i - 1) * N);
		if (p1 == MAP_FAILED || p2 == MAP_FAILED)
		{
			perror("mmap");
			exit(-1);
		}
		for(j = 0; j < (p->len % N); j++)
		{
			p2[j] = p1[j];
			usleep(1000);
			count[p->no]++;
		}
		munmap(p1, p->len % N);
		munmap(p2, p->len % N);
	}
	return NULL;
}
void *thr_fn1(void * arg)
{
	int i = 0;
	int *p = arg;
	int num = 0;
	while(num != size)
	{
		num = 0;
		for (i = 0; i < n; i++)
			num += p[i];
		if((num % (size / n)) == 0)
			putchar('=');
	}
	putchar('\n');
	return NULL;
}

int main(int argc, char *argv[])
{
	if (argc < 3)
	{
		printf("please enter ./a.out file1 file2 number\n");
		exit(-1);
	}

	if(argc >  3)
		n = atoi(argv[3]);
	pthread_t tid[n + 1];
	int i = 0, j;
	struct ITERM iterm_t[n];

	fd1 = open(argv[1],O_RDONLY);
	fd2 = open(argv[2],O_RDWR | O_CREAT | O_TRUNC, 0666);
	size = lseek(fd1, 0, SEEK_END);
	lseek(fd2, size - 1, SEEK_END);
	write(fd2, "\0", 1);

	j = size / N;//共有i个4096字节
	if (size % N)
		j++;
	m = j / n;//一个线程拷贝m个4096字节
	if (j % n)
		m++;

	for (i = 0; i < n - 1; i++)
	{
		iterm_t[i].len = m * N;
		iterm_t[i].offset = i * m * N;
		iterm_t[i].no = i;
		pthread_create(&tid[i], NULL, thr_fn,(void *)&iterm_t[i]);
	}
	iterm_t[i].len = size - (n - 1) * m * N;
	iterm_t[i].offset = i * m * N;
		iterm_t[i].no = i;
	pthread_create(&tid[i], NULL, thr_fn,(void *)&iterm_t[i]);

	pthread_create(&tid[n], NULL, thr_fn1,(void *)&count);
	for(i = 0; i < n + 1; i++)
		pthread_join(tid[i], NULL);
	close(fd1);
	close(fd2);
	return 0;
}
