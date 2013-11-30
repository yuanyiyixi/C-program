#include <stdio.h>
#include <stdlib.h>

struct node{
	char item;
	struct node * next;
};
typedef struct node * link;

link head = NULL;
int main(void)
{
	link p = NULL;

	printf("size of p = %d\n",sizeof(p));
	printf("size of *p = %d\n",sizeof(*p));//常用来计算结构体的大小
	printf("item = %p\n",&(((link) 0)->item));

	p = malloc(sizeof(*p));
	p->item = 'a';
	p->next = NULL;

	head = p;

	p = malloc(sizeof(*p));
	p->item = 'b';
	p->next = NULL;

	head->next = p;//a->b

	p = malloc(sizeof(*p));
	p->item = 'c';
	p->next = NULL;

	head->next->next = p;//a->b->c
	//insert D before head
	/*p = malloc(sizeof(*p));
	  p->item = 'd';
	  p->next = head;

	  head = p;*/

	//insert D after tail
	/*link tail;
	tail = NULL;
	p = head;
	while(p != NULL)
	{
		if(p->next == NULL)
	tail = p;
	p = p->next;
	}
	p = malloc(sizeof(*p));
	  p->item = 'd';
	  p->next = NULL;
	  tail->next = p;*/

	  //insert D after 'b' node
	  /*link pos = head->next;
	  p = malloc(sizeof(*p));
	  p->item = 'd';
	p->next = pos->next;
	pos->next = p;*/

	/*link pos = head->next;
	link prev;
	p = head;
	while(p != NULL)
	{
		if(p->next == pos)
		{
			prev = p;
			break;
		}
		p = p->next;
	}
	p = malloc(sizeof(*p));
	p->item = 'd';
	p->next = pos;
	prev->next = p;*/

	//delete pos == head
	/*link pos = head;
	head = pos->next;
	free(pos);
	pos = NULL;*/

	//delete pos != head
	link pos = head->next;
	//link prev = NULL;
	p = head;
	while(p != NULL)
	{
		if(p->next == pos)
		{
			//prev = p;
			p->next = pos->next;
			break;
		}
		p = p->next;
	}
	//prev->next = pos ->next;
	free(pos);
	pos = NULL;

	//travel list from head
	p = head;
	while(p != NULL)
	{
		printf("p->item = %c\n",p->item);
		p = p->next;
	}
	return 0;
}
