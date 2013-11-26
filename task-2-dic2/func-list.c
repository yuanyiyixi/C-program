#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "public.h"

link head, tail;
link myhead, mytail;
int  insert_tail(link s,link *p, link *q)
{
	if (*p == NULL)
	{
		*p = *q = s;
		return 0;
	}
	(*q)->next = s;
	*q = s;
	(*q)->next = NULL;
	return 0;
}

int load_file(char *filename, link *p, link *q)
{
	FILE *fp;
	fp = fopen(filename,"r");
	if (fp == NULL)
		return 1;
	while(1)	
	{
	char *t = NULL;
	char buf[1024] = "";
		link s = NULL;

		t = fgets(buf, 1024, fp);
		buf[strlen(buf) - 1] = '\0';
		if (t == NULL)
			break;

		s = malloc(sizeof(*s));
		sscanf(buf,"%s",s->words.word);

		t = fgets(buf, 1024, fp);
		buf[strlen(buf) - 1] = '\0';
		strcpy(s->words.trans,buf);

		//t = sscanf(buf, 1024, fp);
/*if(strcmp((char *)p,"myhead") == 0)
{
		t = fgets(buf, 1024, fp);
		buf[strlen(buf) - 1] = '\0';
		s->words.freq = atoi(buf);
}*/
//经函数传进来的p是一个地址
		insert_tail(s, p, q);
	};
	return 0;
}
void print_info(dic_t *p)
{
	printf("%s\n",p->trans);
}
link search_word(char * word, link q)
{
	link p;
	p = q;
	while(p != NULL)
	{
		if(strcmp(p->words.word+1,word) == 0)
		{
			print_info(&p->words);
			return p;
		}
		p = p->next;
	}
	return NULL;
}
int add_word(link p)
{

	link s;
	s = malloc(sizeof(*s));
	s->words = p->words;
	s->words.freq = 1;

	insert_tail(s, &myhead,&mytail);
	return 0;
}
void delete_word(link p)
{
	link prev;
	if(p == myhead)
	{
		myhead = p->next;
		return;
	}
	for (prev = myhead; prev; prev = prev->next)
	{
		if(prev->next == p)
		{
			prev->next = p->next;
			free(p);
			return;
		}
	}
}
void write_to_file(void)
{
	FILE *fp;
	link prev;
	fp = fopen("myadd.txt","w");
	for(prev = myhead; prev; prev = prev->next)
	{
		fputs(prev->words.word,fp);
		fputs("\n",fp);
		fputs(prev->words.trans,fp);
	}
	fclose(fp);
	return ;
}
