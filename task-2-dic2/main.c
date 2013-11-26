#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "public.h"

extern link head, myhead;
extern link tail, mytail;

int main(int argc, char *argv[])
{
	if (argc < 3)
		load_file("myadd.txt",&myhead,&mytail);
	/*else if(strcmp(argv[1],"-f") == 0 )
		if(load_file (argv[2], &myhead, &mytail) == 1)
		{
			printf("load failed\n");
			exit(-1);
		}*/
	while(1)
	{
		char buf[128];
		char str[4];
		link q,q1;
		printf("search$$ ");
		fgets(buf, 128, stdin);
		if(strcmp(buf,"exit\n") == 0)
		{
			write_to_file();
			break;
		}
		parse(buf, &argc, argv);
		q1 = (link)search_word(argv[0],myhead);
		if(q1 != NULL)
		{
			printf("delete this word to myadd.txt (y/n)?\n");
			fgets(str,sizeof(str),stdin);
			if (str[0] == 'y')
				delete(q1);
		}
		else
		{
			load_file("dict.txt",&head, &tail);
			q = (link)search_word(argv[0],head);
			if(q != NULL)
			{
				printf("add this word to myadd.txt (y/n)?\n");
				fgets(str,sizeof(str),stdin);
				if (str[0] == 'y')
					add(q);
			}
			else
			printf("not found!\n");
		}
	}
	return 0;
}
