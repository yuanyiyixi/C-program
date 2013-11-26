struct WORDS
{
	char word[32];
	char trans[1024];
	int freq; 
};
typedef struct WORDS dic_t;

struct node
{
	dic_t words;
	struct node * next;
};
typedef struct node * link;
