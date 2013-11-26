#include <stdio.h>

int load(int argc, char *argv[]);
int list(int argc, char *argv[]);
int sort(int argc, char *argv[]);
int find(int argc, char *argv[]);

struct cmd
{
	char name[16];
	int (*pf)(int argc, char *argv[]);
}cmds[]=
{
	"load",load,
	"list",list,
	"sort",sort,
	"find",find
};

int main(void)
{
	printf("\t\t 欢迎进入学生学籍管理系统\n");
	while(1)
	{
		char buf[128];
		int argc = 0, i = 0;
		char *argv[8];

		printf("请输入您的操作\n");
		fgets(buf, 128, stdin);
		parse(buf, &argc, &argv);
		for (i = 0; i < sizeof(cmds)/sizeof(cmds[0]); i++)
			if(strcmp(argv[0],cmds[i].name) == 0)
				cmds[i].pf(argc,argv);
	}
	return 0;
}
