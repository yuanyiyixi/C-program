#include <stdio.h>
#include <stdlib.h>
#define MAX_ROW 5
#define MAX_COL 5

int maze[MAX_ROW][MAX_COL]={{0,1,0,0,0},
	{0,1,0,1,0},
	{0,0,0,0,0},
	{0,1,1,1,0},
	{0,0,0,1,0}};
struct node
{
	int row;
	int col;
};
struct node *stack;
int size;
int top;

void print_maze(void)
{
	int i, j;
	for (i = 0; i < MAX_ROW; i++)
	{
		for(j = 0; j < MAX_COL; j++)
			printf("%d ", maze[i][j]);
		printf("\n");
	}
}

void push(struct node p)
{
	size++;
	stack = realloc(stack,size * sizeof(*stack));
	stack[top++] = p;
}

struct node point[MAX_ROW][MAX_COL] = {
	{{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1}},
	{{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1}},
	{{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1}},
	{{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1}},
	{{-1,-1},{-1,-1},{-1,-1},{-1,-1},{-1,-1}}};

void visit(int row, int col, struct node pre)
{
	struct node p = {row,col};
	maze[row][col] = 2;
	point[row][col] = pre;//把前一个所在位置赋给point
	push(p);	//走过的坐标压栈
}
struct node pop(void)
{
	return stack[--top];
}

void destory(void)
{
	free(stack);
}

int main(void)
{
	struct node p = {0, 0};
	maze[p.row][p.col] = 2;	//第一个位置坐标置为2，即开始走
	push(p);	//记录所开始位置的坐标
	while (top > 0)
	{
		p = pop();	//栈中第一个元素出栈
		if (p.row == MAX_ROW - 1 && p.col == MAX_COL - 1)//出栈元素为数组中最后一个
			break;	//到达目的地跳出
		 if(p.col + 1 < MAX_COL && maze[p.row][p.col  + 1] == 0)//如果出栈元素的不是所在行的最后一个，并且后一个是0，即能往右走
			visit(p.row, p.col + 1, p);//将后一个元素置为2，并记录当前所在位置
		 if (p.row + 1 < MAX_ROW && maze[p.row + 1][p.col] == 0)
			visit(p.row + 1, p.col, p);//能往下走
		 if(p.col - 1 >= 0 && maze[p.row][p.col - 1] == 0)
			visit(p.row, p.col - 1, p);//能往左走
		 if(p.row - 1 >= 0 && maze[p.row - 1][p.col] == 0)
			visit(p.row - 1, p.col, p);//能往上走
		print_maze();//打印所走的路径
	}
	if(p.row == MAX_ROW -1 && p.col == MAX_COL - 1)//如果能到达终点
	{
		printf("(%d,%d)\n",p.row, p.col);
		while(point[p.row][p.col].row != -1)//如果p点之前还有走过的点
		{
			p = point[p.row][p.col];//把之前的点赋给p，并打印出来
			printf("(%d,%d)\n",p.row, p.col);
		}
	}
	else printf("NO PATH!\n");
	destory();
	return 0;
}
