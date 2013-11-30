#include <stdio.h>
#include <string.h>
//#define N 12000
struct 
{
	int len;
	int freq;
	char wordstr[32];
	char trans[64];
}word[12000],t;

/*int find(char *word,int n)
  {
  for(i = 0; i < n; i++)
  if(strcmp(word[i].wordstr,word) == 0)
  return i;
  else return -1;
  }*/
int main(void)
{
	//char ch;
	char *p;
	int n = 0,i = 0,k = 0,j;
	int tmp = 0;
	int reword[12000] = {-1};
	int newword[12000] = {0};

	while(1)
	{
		char buf[250] = " ";
		// word[n].wordstr = " ";
		p = fgets(buf,sizeof(buf),stdin);
		if(p == NULL)
			break;
		for(i = 0;buf[i] != '\0';i++)
		{
			if(isalpha(buf[i]))
			{
				word[n].wordstr[k] = buf[i];
				k++;
			}
			else if(k != 0 ){
				word[n].wordstr[k] = '\0';
				word[n].len = strlen(word[n].wordstr); 
				word[n].freq = 1;
				//printf("%d:",n+1);
				//printf("%-20s\t",word[n].wordstr);
				//printf("len: %d\n",word[n].len);
				/*if(find(word[n].wordstr, n) == -1)
				  {
				  reword[j] = n;
				  j++;
				  }
				  else 
				  word[find(word[n].wordstr)].freq++;*/
				if(tmp < word[n].len)
					tmp = strlen(word[n].wordstr);
				k = 0;
				n++;
			}
		}
	}
	/*tmp = word[0].len;
	  for(k = 1; k < n; k++)
	  if(tmp < word[k].len)
	  tmp = word[k].len;*/
	for(k = 0; k < n; k++)
		if(word[k].len == tmp)
			printf("len: %d\nword: %s\n",tmp,word[k].wordstr);

	for(k = 0; k < n; k++)
		for(i = 0; i < k; i++)
			if((strcmp(word[k].wordstr,word[i].wordstr) == 0) && k != i)
			{
				reword[i] = i;
				word[i].freq ++;
			}
	if(reword[0] != -1) 
		newword[0] = reword[0];
	//printf("%-20sfreq:%d\n",word[0].wordstr,word[0].freq);
	for(k =  1,j = 1; k < n;j++, k++)
		if(reword[k] != 0)
			newword[j] = reword[k];
	for(k =  1; k < j; k++)
		for(i = 0; i < j-k; i++)
			if(word[newword[i]].freq < word [newword[i+1]].freq)
			{
				t = word[newword[i]];
				word[newword[i]] = word[newword[i + 1]];
				word[newword[i + 1]] = t;
			}
	for(k =  0; k < j; k++)
		//printf("%-20s freq:%d\n",word[k].wordstr,word[k].freq);*/
		printf("%-20slen: %-3dfreq:%d\n",word[newword[k]].wordstr,word[newword[k]].len,word[newword[k]].freq);
	return 0;
}
