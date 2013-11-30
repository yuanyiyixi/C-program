#include <stdio.h>
#include <stdlib.h>

#define N 10	
typedef struct node * link;
struct node 
{
	int item;
	link next;
};

link make_node(int item)//创建节点
{
	link p;
	p = malloc(sizeof(*p));
	p->item = item;
	p->next = NULL;
	return p;
}

link head = NULL;
link tail = NULL;
link q = NULL;

void insert(link p)//插入节点
{
	if(head == NULL)
	{
		head = tail =  p;
		return;
	} 
	tail->next = p; 
	tail = p; 
	return ;
} 
void backout(link p)//指向逆序 
{ 
	head = p->next;//改变一个,head往后挪一个 
	p->next = q;//p的指向变为前一个 
	q = p;//保存当前的p以便于下个节点指向本节点 
} 
void traverse(link t)//遍历节点，并打印 
{ 
	link p; 
	p = t; 
	while(p != NULL) 
	{ 
		printf("p->item = %d\n",p->item); 
		p = p->next;
	}
	return;
}
int main(void)
{
	link p;
	int i = 0;
	for (i = 0; i < N; i++)
	{
		p = make_node(i);
		insert(p);
	}

	p = head;
	while(p != NULL)
	{
		backout(p);
		p = head;//每次指向变换后，head指向下一个节点，即p指向了下一个节点
	}
	head = q;//所有节点的next改变后head为NULL，q为最后一个节点，逆向后变为head
	traverse(head);

	//释放空间
	p = head;
	q = NULL;
	while(p != NULL)
	{
		free(q);
		q = p;
		p = p->next;
	}
	free(q);	//p为NULL时，p的前一个只存放在q中，但没有被释放
	free(head);
	traverse(head);
	return 0;
}
