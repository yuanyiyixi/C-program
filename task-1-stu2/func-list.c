#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "public.h"

typedef struct node * link;
struct node
{
	stu_t student;
	struct node * next;
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
		return;
	}
	tail->next = p;
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
	printf("%14s",p->name);
	printf("%14s",p->cname);
	printf("%3d",p->age);
	printf("%4s",p->gender);
	printf("%12s",p->native);
	printf("%12s",p->mobile);
	printf("%12s",p->qq);
	printf("%20s",p->email);
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

int cmp_name(const void *s1,const void *s2)
{
	return strcmp(((link)*(int *)s1)->student.name,((link)*(int *)s2)->student.name);
}
int cmp_age(const void *s1,const void *s2)
{
	return ((link)*(int *)s1)->student.age - ((link)*(int *)s2)->student.age;
}

void sort_by_name(void)
{
	qsort(students,num,sizeof(link),cmp_name);
	list_all();
	return;
}
void sort_by_age(void)
{
	qsort(students,num,sizeof(link),cmp_age);
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

