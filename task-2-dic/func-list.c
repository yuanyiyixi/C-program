#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "public.h"

link head, tail;
void insert_tail(link s)
{
	if (head == NULL)
	{
		head = tail = s;
		return;
	}
	tail->next = s;
	tail = s;
	return;
}

int load_file(char *filename)
{
	FILE *fp;
	printf("%s file load...\n",filename);
	fp = fopen(filename,"r");
	if (fp == NULL)
		return 1;
	while(1)	
	{
		char *p = NULL;
		char buf[1024] = "";
		link s = NULL;

		p = fgets(buf, 1024, fp);
		buf[strlen(buf) - 1] = '\0';
		if (p == NULL)
			break;

		s = malloc(sizeof(*s));
		sscanf(buf,"%s",s->words.word);

		p = fgets(buf, 1024, fp);
		buf[strlen(buf) - 1] = '\0';
		strcpy(s->words.trans,buf);

		insert_tail(s);
	};
	printf("load finished\n");
	return 0;
}
void print_info(dic_t *p)
{
	printf("%s\n",p->trans);
}
int search_word(char * word)
{
	link p;
	p = head;
	while(p != NULL)
	{
		if(strcmp(p->words.word+1,word) == 0)
			print_info(&p->words);
		p = p->next;
	}
	return;
}

int add_word(char *word)
{
	return 0;
}
