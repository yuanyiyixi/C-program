#include <stdio.h>
#include <string.h>
struct stu 
{
	char name[20];
	int id;
	char sex;
};
int main (void)
{
	int i;char tmp;
	char a[4];
	struct stu s[100];
	for (i=0;strcmp(a,"exe");i++)
	{
		scanf("%s%c%d%c%c",s[i].name,&tmp,&s[i].id,&tmp,&s[i].sex);
		scanf("%s",a);
	}
	for (i=0;strcmp(a,"exe");i++)
	{
		printf ("%s\n",s[i].name);
		printf ("%d\n",s[i].id);
		printf ("%c\n",s[i].sex);
	}
	return 0;
}
