#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct STU
{
	int id;
	char name[20];
	char sex;
};

char str[20];

void input(struct STU student[],int i)
{
	fgets(str,sizeof(str),stdin);
	str[strlen(str) - 1] = '\0';
	student[i].id = atoi(str);

	fgets(str,sizeof(str),stdin);
	str[strlen(str) - 1] = '\0';
	strcpy(student[i].name,str);

	fgets(str,sizeof(str),stdin);
	student[i].sex = str[0];
	return ;
}
void output(struct STU student[], int num)
{
	int i = 0, j = 0;
	struct STU tmp;
	for (i = 1; i < num; i++)
		for (j = 0; j < num -i; j++)
			if(strcmp(student[j].name,student[j+1].name)>0)
			{
				tmp = student[j];
				student[j] = student[j + 1];
				student[j + 1] = tmp;
			}

	for(i = 0; i < num; i++)
		printf("%d\t%s\t%c\n",student[i].id,student[i].name,student[i].sex);
	return ;
}
int main(int argc,char *argv[])
{ int num = 0;
	if(argc < 2)
	{
		printf("please enter ./a.out num\n");
		exit(-1);
	}
	num = atoi(argv[1]);

	char ch;
	int i, j = 0; 
	struct STU *p, *q, student[num];
	
	p = calloc(num,sizeof(struct STU));
	q = p;
	q = student;
	for(i = 0; i < num; i++)
		input(student,i);
	while(1)
	{
		printf("是否继续录入学生信息？(Y/N)");
	fgets(str,sizeof(str),stdin);
	ch = str[0];
		if(ch == 'N' || ch == 'n')
		{
			output(student,num);
			break;
		}
		else if(ch == 'Y' || ch == 'y')
		{
			printf("请输入继续输入学生的数量:\n");

			fgets(str,sizeof(str),stdin);
			str[strlen(str) - 1] = '\0';
			j = atoi(str);

			p = realloc(p,sizeof(struct STU) * (num + j));
			for(i = num; i < num + j; i++)
				input(student,i);
			num += j;
		}
	}
	free(p);
	return 0;
}
