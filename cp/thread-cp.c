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
	char *s, *d;
struct ITERM{
	int len;
	int offset;
	int no;
};
void *thr_fn(void *arg)
{
	struct ITERM *t = arg;
	int j, i = 1;
	char *p, *q;

		p = s + t->offset;
		q = d + t->offset;

		for(j = 0; j < t->len; j++)
		{
			q[j] = p[j];
			count[t->no]++ ;
			usleep(10);
		}
	return NULL;
}
void *thr_fn1(void * arg)
{
	int i = 0,j;
	int *p = arg;
	int num = 0,draw = 0;
	while(num != size)
	{
		num = 0;
		for (i = 0; i < n; i++)
			num += p[i];
		j = (num / (size / 20)) + 1;
		for (; draw < j; draw++)
			putchar('=');
			fflush(stdout);
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
	int i = 0;
	struct ITERM iterm_t[n];

	fd1 = open(argv[1],O_RDONLY);
	fd2 = open(argv[2],O_RDWR | O_CREAT | O_TRUNC, 0666);
	size = lseek(fd1, 0, SEEK_END);
	lseek(fd2, size - 1, SEEK_END);
	write(fd2, "\0", 1);

	m = size / n;//一个线程拷贝m个字节
	if (size % n)
		m++;

		s = mmap(NULL, size, PROT_READ, MAP_PRIVATE, fd1, 0);
		d = mmap(NULL, size, PROT_WRITE, MAP_SHARED, fd2, 0);
		if (s == MAP_FAILED || d == MAP_FAILED)
		{
			perror("mmap");
			exit(-1);
		}

	close(fd1);
	close(fd2);
	for (i = 0; i < n - 1; i++)
	{
		iterm_t[i].len = m ;
		iterm_t[i].offset = i * m ;
		iterm_t[i].no = i;
		pthread_create(&tid[i], NULL, thr_fn,(void *)&iterm_t[i]);
	}
	iterm_t[i].len = size - (n - 1) * m;
	iterm_t[i].offset = i * m ;
		iterm_t[i].no = i;
	pthread_create(&tid[i], NULL, thr_fn,(void *)&iterm_t[i]);

	pthread_create(&tid[n], NULL, thr_fn1,(void *)&count);
	for(i = 0; i < n + 1; i++)
		pthread_join(tid[i], NULL);

		munmap(s, size);
		munmap(d, size);
	return 0;
}
