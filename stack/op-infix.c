#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * stack1;
int * stack2;
int top1;
int top2;
int size1;
int size2;

void push1(char ch)
{
	size1++;
	stack1 = realloc(stack1, size1 * sizeof(*stack1));
	stack1[top1++] = ch;
}
void push2(int a)
{
	size2++;
	stack2 = realloc(stack2, size2 * sizeof(*stack2));
	stack2[top2++] = a;
}
int pop1(void)
{
	return stack1[--top1];
}
int pop2(void)
{
	return stack2[--top2];
}
int is_empty(void)
{
	return top1 == 0;
}
void destory(void)
{
	free(stack1);
	free(stack2);
}

int main(void)
{
	char buf[1024] = "";
	char *p = NULL;
	fgets(buf,sizeof(buf),stdin);
	p = strtok(buf," \n");
	push2(atoi(p));
	while((p = strtok(NULL, " \n")) != NULL)
	{
		char op;
		int b, a;
		switch(*p)
		{
			case '+':
			case '-':
					//if(!is_empty())
					{
						while (top1 != 0) {
							op = pop1();
							//if(*op == ' ')
							//	break;
						b = pop2(); 
						a = pop2(); 
							if(op == '+')
						push2(a + b);
						else 
						push2(a - b);
						};
					}
						push1(*p);
						break;
	 		case '*':
			case '/':
						push1(*p);
						break;
			default: push2(atoi(p));
		}
	}
 switch(pop1()){
	 case '+': printf("%d\n",pop2() + pop2());break;
	 case '-': printf("%d\n",pop2() - pop2());break;
	 case '*': printf("%d\n",pop2() * pop2());break;
	 case '/': printf("%d\n",pop2() / pop2());break;
 }
	//printf("%d\n",pop2());
	destory();
	return 0;
}
