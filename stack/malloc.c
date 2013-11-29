#include <stdio.h>
#include <stdlib.h>
char *stack;
int size;
int top = 0;
void push(char c)
{
	if(top == size)
	{
		size += size;
		stack = realloc(stack ,size * sizeof( *stack));
	}
}
char pop(void)
{
	return stack[--top];
}
int is_empty(void)
{
	return top == 0;
}
int  init(int sz)
{
	size = sz; 
	stack = malloc(sz * sizeof(*stack));
	if(!stack)
		return -1;
		return 0;
}
void destory_stack(void)
{
	free(stack);
}
int main(void)
{
	char ch;
	init(5);
	while((ch = getchar())!= '\n')
		push(ch);
		while(!is_empty())
			putchar(pop());
			destory_stack();
	return 0;
}
