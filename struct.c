#include <stdio.h>
#include <string.h>
struct stud
{
	unsigned short id;
	char name[10];
	int s[4];
	double ave;
}st[10];
int main()
{
	struct stud tmp;
	int n=0;int i,j,len;
	char str[10];
	for(i=0;i<10;i++)
	{
		fgets(str,sizeof(str),stdin);
		len = strlen(str);
		str[len -1]='\0';
		st[i].id=atoi(str);

		fgets(str,sizeof(str),stdin);
		len = strlen(str);
		str[len -1]='\0';
		strcpy(st[i].name,str);

		for(j=0;j<4;j++)
		{
			fgets(str,sizeof(str),stdin);
			len = strlen(str);
			str[len -1]='\0';
			st[i].s[j]=atoi(str);
			n += st[i].s[j];
		}
		st[i].ave = n/4;
		n=0;
	}
	for (i=1;i<10;i++)
		for(j=0;j<10-i;j++)
		{
			if (st[j].ave > st[j+1].ave)
			{
				tmp=st[j];
				st[j]=st[j+1];
				st[j+1]=tmp;
			}
		}
	printf("id\tname\ts[0]\ts[1]\t[2]\ts[3]\tave\n");
	for(i=0;i<10;i++)
		printf("%hd\t%s\t%d\t%d\t%d\t%d\t%.2f\n",st[i].id,st[i].name,st[i].s[0],st[i].s[1],st[i].s[2],st[i].s[3],st[i].ave);
	for (i=1;i<10;i++)
		for(j=0;j<10-i;j++)
		{
			if (strcmp(st[j].name,st[j+1].name)>0)
			{
				tmp=st[j];
			st[j]=st[j+1];
			st[j+1]=tmp;
			}
		}
	printf("id\tname\ts[0]\ts[1]\t[2]\ts[3]\tave\n");
	for(i=0;i<10;i++)
		printf("%hd\t%s\t%d\t%d\t%d\t%d\t%.2f\n",st[i].id,st[i].name,st[i].s[0],st[i].s[1],st[i].s[2],st[i].s[3],st[i].ave);
		return 0;
}
