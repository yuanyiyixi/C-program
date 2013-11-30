#include <stdio.h>

int main(void)
{
	char ch;
	char *p;
	int n = 0,i = 0;

	
		printf("%d:",1);
	while(1)
	{
	char buf[128]= " ";
		p = fgets(buf,sizeof(buf),stdin); 
		if(p == NULL)
			break;
		//printf("%d:",n+1);
		for(i= 0;buf[i] != '\n';i++)
		{	
			//ch = buf[i];
			if(isalpha(buf[i]))
			{
				printf("%c",buf[i]);
				//continue;
			}
			else if(isalpha(buf[i+1])||(buf[i+1]=='\n')) 
			{ 
				n++;	
				printf("\n");
				printf("%d:",n+1);
			}
				//else if(buf[i]=='\n')n++;//printf("\n");
		}
			//	printf("\n");
	}
	return 0;
}
