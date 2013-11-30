#include <stdio.h>
#include <stdlib.h>
struct node
{
	char item;
	struct node * l,*r;
};

typedef struct node *link;

link root = NULL;

link make_node(char item)
{
	link p;
	p = malloc(sizeof(*p));
	p->item = item;
	p->l = NULL;
	p->r = NULL;
	return p;
}
link insert(link t, unsigned char key)
{
	if(!t)
		return make_node(key);
	if(t->item > key)
		t->l = insert(t->l, key);
	else t->r = insert(t->r, key);
	//printf("t->item = %d\n",t->item);

	return t;
}
link search(link t, char key)
{
	if (t == NULL)
		return NULL;
	if(key > t->item)
		return search(t->r,key);
	else if(key < t->item)
		return search(t->l, key);
	return t;
}

int count(link t)
{
	if(!t)
		return 0;
	return 1 + count(t->l) + count(t->r);
}
int depth(link t)
{
	int dl, dr;
	if (!t)
		return 0;
	dl = depth(t->l);
	dr = depth(t->r);
	return 1 + (dl > dr ? dl:dr);
}
int is_balance(link t)
{
	if( t == NULL)
		return 1;
	int lc = depth(t->l);
	int rc = depth(t->r);
	if (lc - rc >= 2 || rc - lc >= 2)
		printf("t->item  = %c is not balance \n",t->item);
#if 0
	int lb = is_balance(t->l);
	int rb = is_balance(t->r);
	if(lb == 0 || rb == 0)
		return 0;
#endif
#if 0
	int lb = is_balance(t->l);
	if(lb == 0)
		printf(" t->l->item = %c is not balance\n",t->l->item);
	int rb = is_balance(t->r);
	if(rb == 0)
		printf(" t->r->item = %c is not balance\n",t->r->item);
	if(lb == 0 || rb == 0)
		return 0;
#endif
	if (lc - rc >= 2 || rc - lc >= 2)
		return 0;
	return 1;
}

void traverse(link t)
{
	if(t == NULL) 
	{
		printf("()");
		return;
	}

	printf("(%c",t->item);
	traverse(t->l);
	//printf("(%c",t->item);
	traverse(t->r);
	//printf("t->item = %c\n",t->item);
	printf(")");
	return;
}
link init(int VLR[], int LVR[], int n)
{
	link t;
	int k;
	if(n <= 0)
		return NULL;
	for (k = 0; VLR[0] != LVR[k]; k++);
	t = make_node(VLR[0]);
	t->l = init(VLR+1, LVR, k);
	t->r = init(VLR+k+1, LVR+k+1, n-k-1);
	return t;
}
int main(void)
{
#if 1
	//int VLR[] = {4,2,1,3,5,6,7};
	//int LVR[] = {1,2,3,4,6,5,7};
	//root = init(VLR, LVR, 7);
	char c;
	while ((c =getchar()) != '\n')
	{
		root = insert(root, c);
		//	printf("root->item = %c\n",root->item);
	}
#endif

	while (1)
	{
		char ch = getchar();
		getchar();
		link p = search(root, ch);
		if (p != NULL)
			printf("%c is found\n",ch);
		else printf("%c is not found\n",ch);
	}

#if 0
	link a, b, c, d, e, f;
	a = make_node('4');
	b = make_node('2');
	c = make_node('5');
	d = make_node('1');
	e = make_node('3');
	f = make_node('6');

	a->l = b;
	a->r = c;
	//b->l = d;
	b->r = e;
	e->r = f;

	root = a;
#endif

	printf("\\tree");
	traverse(root);
	printf("\n");
#if 0
	int m = count(root);
	int n = depth(root);
	printf("count = %d\n",m);
	printf("depth = %d\n",n);

	int s = 1;
	while (n--)
		s *= 2; 
	if ((s - 1) == m)
		printf("full\n");
	else printf("NO full\n");

	if (is_balance(root))
		printf("balance\n");
	else printf("no balance\n");
#endif

	return 0;
}
