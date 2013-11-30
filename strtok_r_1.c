#include <stdio.h>
#include <string.h>
int main(void)
{
	char str[] = "<html>bhrg<html>njk<dkf><jfi>hdenji";
	char *token;// *saveptr;
	/*strcpy(str,strchr(str,'>')+1);
	  token = strtok(str,"<");
	  printf("%s\n",token);
	  return 0;*/
	token = strtok(str,">");
	token = strtok(NULL,"<");
		printf("%s\n",token);
	while(1)
	{
			token = strtok(NULL,"<");
			token = strtok(NULL,">");
			if(token == NULL)
				break;
			printf("%s\n",token);
	}

	return 0;
}
