#include <stdio.h>

int main(void)
{
	//char ch;
	char *p;
	int n = 0,i = 0,k = 0;

	while(1)
	{
		char buf[250] = " ";
		char word[32] = " ";
		p = fgets(buf,sizeof(buf),stdin);
		if(p == NULL)
			break;
		for(i = 0;buf[i] != '\0';i++)
		{
			if(isalpha(buf[i]))
			{
				word[k] = buf[i];
				k++;
			}
			else if(k != 0 ){
				word[k+1] = '\0';
				printf("%d:",n+1);
				printf("%s\n",word);
				k = 0;
				n++;
			}
		}
	}
	return 0;
}
