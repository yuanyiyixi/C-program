#include <stdio.h>
#include <stdlib.h>
char *queue;
int head, tail, qc;
int sz;
void init(int size)
{
	sz = size;
	queue = malloc(size * sizeof(*queue));
	head = tail = 0;
	qc = 0;
}
void inqueue(char ch)
{
	queue[tail++] = ch;
	tail %= sz;
	qc++;
}
char outqueue(void)
{
	char ch = queue[head++];
	head %= sz;
	qc--;
	return ch;
}
int is_full(void)
{
	return qc == sz;
}
int is_empty(void)
{
	return qc == 0;
}
void detory(void)
{
	free(queue);
}
int main(void)
{
	char ch;
	init(10);
	while(!is_full() && (ch = getchar()) != '\n')
	inqueue(ch);
	while(!is_empty())
		putchar(outqueue());
		putchar('\n');
		return 0;
}
