#include <stdio.h>
#include "test.h"

#  define PI 3.14
#define STR "hello\
	world"

#define PRINTD(a) printf(#a " = %d\n",a)
#define PRINTS(a) printf(#a " = %s\n",a)
	int a;/*abc*/int b;
	//test
	int c;
int main(void)
{
	a = 100;
	b = 200;
#ifdef DEBUG 
	PRINTD(a);
	PRINTD(b);
#elif MAX
	PRINTD((a+b));
	PRINTD((a-b));
#endif
	PRINTD((a*b));
	PRINTD((a/b));
	PRINTD(__STDC__);
	PRINTD(__LINE__);
	PRINTS(__FILE__);
	PRINTS(__func__);
	PRINTS(__TIME__);
	//printf("file name is %s\n",__FILE__);
	//printf("func is %s\n",__func__);
	//printf("time is %s\n",__TIME__);
//	printf("date is %s\n",__DATE__);
/*	SWITCH ("abc")
	{
		CASE "abc":
		printf("this is abc\n");
		BREAK;
		CASE "123":
		printf("this is 123\n");
		BREAK;
		DEFAULT:
		BREAK;
	}
	printf("hello world\n"
	"good boy\n");
	printf("%s\n",STR);*/
	
	return 0;
}
