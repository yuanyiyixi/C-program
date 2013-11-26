#include <stdio.h>
#include <string.h>
#include "public.h"

/*int load(char *file, link p,link q)
{
	printf("./mydict ");
	printf("%s file load...\n",file);
	int a = load_file(file, p, q);
	printf("load finished\n");
	return a;
}*/


int add(char *word, int len)
{
	add_word(word,len);
	return 0;
}
int delete(link p)
{
	delete_word(p);
	//write_to_file();
	return 0;
}
