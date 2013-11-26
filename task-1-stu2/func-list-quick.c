#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "public.h"

typedef struct node * link;
struct node
{
	stu_t student;
	struct node * next;
	struct node * prev;
};

link head = NULL;
link tail = NULL;
link students[40];
int num = 0;

void insert_tail(link p)
{
	if (head == NULL)
	{
		head = tail = p;
		head->next = tail;
		head->prev = tail;
		return;
	}
	tail->next = p;
	tail->next->prev = tail;
	tail = p;
	return;
}

void load_file(char * filename)
{
	int i = 0;
	FILE *fp;
	printf("loading... file %s\n",filename);
	fp = fopen(filename,"r");
	for (i = 0; ; i++)	
	{
		int ret = 0;
		char *p = NULL;
		char buf[256] = "";
		link s = NULL;

		p = fgets(buf, 256, fp);
		buf[strlen(buf) - 1] = '\0';
		if (p == NULL)
			break;

		s = malloc(sizeof(*s));
		ret = sscanf(buf,"%s %s %d %s %s %s %s %s %s\n",
				s->student.name,s->student.cname,
				&s->student.age,s->student.gender,
				s->student.native,s->student.mobile,
				s->student.qq,s->student.email,
				s->student.hobby);
		insert_tail(s);
		students[i] = s;
	}
	num = i;
	printf("all students num is %d\n",num);
	return;
}

void print_info(stu_t *p)
{
	printf("%s",p->name);
	printf("%s",p->cname);
	printf("%d",p->age);
	printf("%s",p->gender);
	printf("%s",p->native);
	printf("%s",p->mobile);
	printf("%s",p->qq);
	printf("%s",p->email);
	printf("%s\n",p->hobby);
	return;
}

void list_name(char *name)
{
	link p;
	p = head;
	while (p != NULL)
	{
		if(strcmp(p->student.name,name))
			print_info(&p->student);
		p = p->next;
	}
	return;
}

void list_all(void)
{
	int i = 0;
	for (i = 0; i < num; i++)
	{
		link p;
		p = students[i];
		print_info(&p->student);
	}
	return;
}

void swap(link *a, link *b)
{
	link tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
	return ;
}
int partition_name(link students[], int l, int r)
{
	int i, j;
	for (i = l + 1, j = l; i <= r; i++)
		if(strcmp(students[i]->student.name, students[l]->student.name) < 0)
			swap(&students[i], &students[++j]);
	swap(&students[j], &students[l]);
	return j;
}
void quick_name(link students[], int l, int r)
{
	if (l >= r)
		return;
	int k = partition_name(students, l, r);
	quick_name(students, l, k-1);
	quick_name(students, k+1, r);
	return;
}
void sort_by_name()
{
	quick_name(students, 0, num - 1);
	list_all();
	return;
}
int partition_age(link students[], int l, int r)
{
	int i, j;
	for (i = l + 1, j = l; i <= r; i++)
		if(students[i]->student.age < students[l]->student.age)
			swap(&students[i], &students[++j]);
	swap(&students[j], &students[l]);
	return j;
}
void quick_age(link students[],int l, int r)
{
	if (l >= r)
		return;
	int k = partition_age(students, l, r);
	quick_age(students, l, k-1);
	quick_age(students, k+1, r);
}
void sort_by_age(void)
{
	quick_age(students, 0, num-1);
	list_all();
	return;
}
void find_native(char * native)
{
	link p;
	p = head;
	while(p != NULL)
	{
		if(strcmp(p->student.native, native) == 0)
			print_info(&p->student);
		p = p->next;
	}
	return;
}
void find_hobby(char * hobby)
{
	link p;
	p = head;
	while(p != NULL)
	{
		if(strstr(p->student.hobby, hobby) != NULL)
			print_info(&p->student);
		p = p->next;
	}
	return;
}
