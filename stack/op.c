#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int  * stack;
int top, size;
void push(int a)
{
	if(top == size)
	{
	size += size;
	stack = realloc(stack,size * sizeof(* stack));
	}
	stack[top++] = a;
}
int pop(void)
{
	return stack[--top];
}
void destory(void)
{
	free(stack);
}
int  init(int sz)
{
	size = sz;
	stack = malloc(sz * sizeof(*stack));
	if(!stack)
		return -1;
		return 0;
}
int main(void)
{
	char buf[128] = "";
	char *p  = NULL;
	init(100);
	printf("enter your number:\n");
	fgets(buf, sizeof(buf),stdin);
	p = strtok(buf, " \n");
	if(p == NULL)
	{
		printf("input error\n");
		exit(-1);
	}
	push(atoi(p));
	while(p != NULL)
	//while((p = strtok(NULL, " \n")) != NULL)
	{
		p = strtok(NULL," \n");
		if(p == NULL)
			break;
			int a, b;
		switch(*p){
			case '+':
			 b= pop();
			 a= pop();
			push(a + b);	
					 break;
			case '-':
			 b= pop();
			 a= pop();
			push(a-b);	
					 break;
			case '*':
			 b= pop();
			 a= pop();
			push(a*b);	
					 break;
			case '/':
			 b= pop();
			 a= pop();
			push(a/b);	
					 break;
			default:push(atoi(p));
		}
	}
	printf("%d\n",pop());
	destory();
	return 0;
}
