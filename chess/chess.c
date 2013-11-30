#include <stdio.h>

void output(char str[][14])
{
	int i,j;
	for(i = 0; i < 13; i++)
	{
		for(j = 0;j < 13; j++)
			printf("%c ", str[i][j]);
		printf("\n");
	}
	return ;
}
int input(char str[][14],int i)
{
	int a, b;
	printf("player %d:",(i % 2)+1);
	scanf("%d%d",&a,&b);
	if (str[a + 2][b + 2] == '*'){
		if (i % 2 == 0)
			str[a + 2][b + 2] = '0';
		else str[a + 2][b + 2] = '1';
		i++;
	}
	else{ 
		printf("%d %dis not permitted! please reinput.\n",a,b);
	}
	return i;
}
int judgment(char a[][14]) 
{
	int k = 1, i, j;
	for (i = 2; i < 13; i++)
	{
		for (j = 2;j < 13; j++)
		{
			while (a[i][j]  == a[i][j + k]) {
				k++;
				if(k==5){
					if(a[i][j] == '0')
					return 0;
					else if (a[i][j] == '1')
						return 1;
				}
			}
			k = 1;
			while(a[i][j] == a[i+k][j+k]){
				k++;
				if(k==5){
					if(a[i][j] == '0')
					return 0;
					else if (a[i][j] == '1')
						return 1;
				}
			}	
			k = 1;
			while(a[i][j] == a[i-k][j+k]){
				k++;
				if(k==5){
					if(a[i][j] == '0')
					return 0;
					else if(a[i][j] == '1')
						return 1;
				}
			}
			k = 1;
			while (a[i][j] == a[i + k][j]){
				k++;
				if(k==5){
					if(a[i][j] == '0')
					return 0;
					else if(a[i][j] == '1')
						return 1;
				}
			}
			k = 1;
		}
	}
	for (i = 2;i < 13; i++)
		for(j = 2;j < 13; j++)
			if (a[i][j] == '*')
				return 2;
	return 3;
}
int main (void)
{
	char a[][14] = {"  0123456789 "," ----------- ","0|********** ","1|********** ",								"2|********** ","3|********** ","4|********** ","5|********** ",								"6|********** ","7|********** ","8|********** ","9|********** "," "};
	int i = 0, j;
	output(a);
	printf("you can input 4 4 to put a chess on board\n");
	while (1)
	{
		i = input(a,i);
		output(a);
		j = judgment(a);
		if (j == 0){
			printf("player 1 is  win\n");
			break;
		}
		else if(j == 1){
			printf("player 2 is  win\n");
		break;
		}
		else if(j == 3){
			printf ("A draw in chess\n");
			break;
		}
	}
	return 0;
}
