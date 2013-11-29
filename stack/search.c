#include <stdio.h>
#include <stdlib.h>
char * stack;
int size;
int top = 0;

struct node
{
	char ch;
	int l;
	int r;
};
struct node a[] = {{'a',1,2},{'b',3,4},{'c',5,6},{'d',-1,-1},{'e',-1,-1},{'f',-1,-1},{'g',-1,-1}};

void push(char ch)
{
	size++;
	stack = realloc(stack,size * sizeof(*stack));
	stack[top++] = ch;
}

char pop(void)
{
	return stack[--top];
}

void destory(void)
{
	free(stack);
}

void push_all(struct node t)
{
	static int i ;
	push(t.ch);
	if(t.r != -1) push_all(a[t.r]);
	if(t.l != -1) push_all(a[t.l]);
}
int main(void)
{
	push_all(a[0]);
	while(top >= 0)
		putchar(pop());
		destory();
		putchar('\n');
		return 0;
}
