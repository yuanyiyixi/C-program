#include <stdio.h>
#include <stdlib.h>

struct node
{
	char ch;
	int l;
	int r;
};
struct node a[] = {{'a',1,2},{'b',3,4},{'c',5,6},{'d',-1,-1},{'e',-1,-1},{'f',-1,-1},{'g',-1,-1}};

char *queue;
int head,tail,qc,size;

void enqueue(char ch)
{
	size++;
	queue = realloc(queue,size * sizeof(*queue));
	queue[tail++] = ch;
	qc++;
}

void search_bfs(struct node t)
{
	enqueue(t.ch);
	qc++;
	while (head != tail)
	{
		t = a[head];
		if(t.l != -1)
		{
			enqueue(a[t.l].ch);
			qc++;
		}
		if(t.r != -1)
		{
			enqueue(a[t.r].ch);
			qc++;
		}
			head++;
	}
}
char outqueue(void)
{
	char ch = queue[head++];
	qc--;
	return ch;
}

void destory(void)
{
	free(queue);
}

int main(void)
{
	search_bfs(a[0]);
	head = 0;
	while(qc > 0)
		putchar(outqueue());
		putchar('\n');
		destory();
		return 0;
}
