#include <stdio.h>
#include <stdlib.h>

#define N	100	
#define OUT 3

typedef struct node * link;

struct node
{
	int id;
	link next;
};

link make_node(int id)
{
	link p;
	p = malloc(sizeof(*p));
	p->id = id;
	p->next = NULL;
	return p;
}

link head = NULL;
link tail = NULL;

void insert_tail(link p)
{
	//first insert
	if(head == NULL)
	{
		head = tail = p;
		return;
	}
	//next insert 
	tail->next = p;
	tail = p;

	return ;
}

void traverse(link t)
{
	link p;

	p = t;
	while (p != NULL)
	{
		printf("p->id = %d\n",p->id);
		p = p->next;
	}

	return;
}

void delete(link p)
{
	if(p == head)
		head = p->next;
	else
	{
		link pre;

		for(pre = head; pre; pre = pre->next)
			if(pre->next == p)
				pre->next = p->next;
	}
	free(p);

	return;
}

int main(void)
{
	int i = 0;
	int step = 0;
	int countoff = 0;
	link p;
	printf("demo JOsephus ring\n");

	for(i = 0; i < N; i++)
	{
		p = make_node(i+1);
		//printf("p->id = %d\n",p->id);
		insert_tail(p);
	}

	//print all list id
	traverse(head);

	//begin to loop
	p = head;
	step = 0;
	countoff = 0;
	while(1)
	{
		link out;
		link save;

		step++;
		countoff++;

		printf("step %d: %d countoff: %d\n", step, p->id,countoff);

		save = p;
		p = p->next;
		/*if(countoff == OUT)
		{
			countoff = 0;

			//kick sb.(p) out
			out = p;
			printf("who is out %d\n",out->id);
		}*/

		//p = p->next;
		if (p == NULL)
			p = head;

		/*if(countoff == 0)
			delete(out);*/
			if(countoff == OUT)
			{
				countoff = 0;
			printf("who is out %d\n",save->id);
			delete(save);
			}

		if(head == NULL)
			break;
	}

	return 0;
}
