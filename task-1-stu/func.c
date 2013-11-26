#include <stdio.h>
#include <string.h>
#include "public.h"

stu_t students[40];
int num = 0;

void load_file(char * filename, stu_t * p)
{
	FILE *fp;
	printf("loading file %s\n",filename);
	fp = fopen(filename,"r");
	int i = 0;

	for(i = 0; p != NULL; i++)
	{
		int ret;
		char buf[256] = "";
		char *p;
		p = fgets(buf,256,fp);
		buf[strlen(buf)-1]='\0';
		ret = sscanf(buf, "%s %s %d %s %s %s %s %s %s",
				students[i].name,students[i].cname,
				&students[i].age,students[i].gender,
				students[i].native,students[i].mobile,
				students[i].qq,students[i].email,
				students[i].hobby);

		if(ret > 0)
		{
			printf("ret = %d\n",ret);
			printf("line: %d, buf: <%s>\n",i,buf);
		}
		if(p == NULL)
			break;
	}
	num = i;
	printf("all students is %d \n",num);
	return;
}

int load(int argc, char *argv[])
{
	printf("load cmd\n");
	load_file(argv[1],students);
	return 0;
}

void list_all(void)
{
	int i = 0;
	for (i = 0; i < num; i++)
	{
		printf("student %d info: %-14s %-10s %-2d %-4s %-10s %-11s %-11s %-25s %-s\n",i,
				students[i].name,students[i].cname,
				students[i].age,students[i].gender,
				students[i].native,students[i].mobile,
				students[i].qq,students[i].email,
				students[i].hobby);
	}
	return;
}

int cmp_name(void *s1, void *s2)
{
	return strcmp((*(stu_t *)s1).name,(*(stu_t *)s2).name); 
}

int cmp_age(void *s1, void *s2)
{
	return (*(stu_t *)s1).age - (*(stu_t *)s2).age;
}

int sort_by_name(void)
{
	qsort(students, num, sizeof(stu_t), cmp_name);
	list_all();
	return;
}
int sort_by_age(void)
{
	qsort(students, num, sizeof(stu_t), cmp_age);
	list_all();
	return;
}
int list(int argc, char *argv[])
{
	printf("list cmd\n");
	list_all();
	return 0;
}
int sort(int argc, char *argv[])
{
	printf("sort cmd\n");
	if(strcmp(argv[1],"name") == 0)
		sort_by_name();
	if(strcmp(argv[1],"age") == 0)
		sort_by_age();
	return 0;
}
void find_native(char * native)
{
	int i = 0;
	for(i = 0; i < num; i++)
	{
		if(strcmp(students[i].native,native) == 0)
		printf("%-14s %-10s %-2d %-4s %-10s %-11s %-11s %-25s %-s\n",
					students[i].name,students[i].cname,
					students[i].age,students[i].gender,
					students[i].native,students[i].mobile,
					students[i].qq,students[i].email,
					students[i].hobby);
	}
	return;
}
void find_hobby(char * hobby)
{
	int i =0;
	for(i = 0; i < num; i++)
	{
		if(strstr(students[i].hobby,hobby)) 
		printf("%-14s %-10s %-2d %-4s %-10s %-11s %-11s %-25s %-s\n",
					students[i].name,students[i].cname,
					students[i].age,students[i].gender,
					students[i].native,students[i].mobile,
					students[i].qq,students[i].email,
					students[i].hobby);

	}
	return;
}
int find(int argc, char *argv[])
{
	printf("find cmd\n");
	if(strcmp(argv[1],"native") == 0)
		find_native(argv[2]);
	if(strcmp(argv[1],"hobby") == 0)
		find_hobby(argv[2]);
	return 0;
}
