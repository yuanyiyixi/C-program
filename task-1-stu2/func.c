#include <stdio.h>
#include <string.h>
#include "public.h"

extern void load_file(char * filename);
extern void sort_by_name(void);
extern void sort_by_age(void);
extern void find_native(char * native);
extern void find_hobby(char * hobby);
extern void list_all(void);
extern void list_name(char *name);


int load(int argc, char *argv[])
{
	printf("load cmd\n");
	load_file(argv[1]);
	return 0;
}
int list(int argc, char *argv[])
{
	printf("list cmd\n");
	if(argc == 1)
	list_all();
	else 
		list_name(argv[1]);
return 0;
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

int sort(int argc, char *argv[])
{
	printf("sort cmd\n");
	if(strcmp(argv[1],"name") == 0)
		sort_by_name();
	if(strcmp(argv[1],"age") == 0)
		sort_by_age();
		return 0;
}
