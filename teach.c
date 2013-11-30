#include <stdio.h>
#include <string.h>
struct teach
{
	int id;
	char name[20];
	char sex;
	int age;
};
int main ()
{
	struct teach t[5];
	struct teach tmp;
	int i,len,j;
	char str[20];
	for (i=0;i<5;i++)
	{
		fgets(str,sizeof (str),stdin);
		len = strlen (str);
		str[len - 1]='\0';
		t[i].id = atoi(str);

		fgets(str,sizeof (str),stdin);
		len = strlen (str);
		str [len -1]='\0';
		strcpy (t[i].name,str);

		fgets(str,sizeof (str),stdin);
		t[i].sex = str[0];

		fgets (str,sizeof (str),stdin);
		len = strlen(str);
		str [len -1] = '\0';
		t[i].age = atoi(str);
	}
	for(i=1;i<5;i++)
	{
		for(j=0;j<5-i;j++)
		{
			if (t[j].id>t[j+1].id)
			{
				tmp=t[j];
				t[j]=t[j+1];
				t[j+1]=tmp;
			}
		}
	}
	for (i=0;i<5;i++)
	{
		printf("%d\t%s\t%d\t%c\n",t[i].id,t[i].name,t[i].age,t[i].sex);
		//printf ("%s\t",t[i].name);
		//printf ("%c\t",t[i].sex);
		//printf ("%d\n",t[i].age);
	}
	return 0;
}
