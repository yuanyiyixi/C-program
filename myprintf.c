#include <stdio.h>
#include <stdarg.h>

char buf[18];
int myprintf(const char *format,...)
{
	va_list ap;
	char ch,c,*p;
	double q;
	int a;
	va_start(ap,format);
	while((ch = *format++) != '\0')
	{
		if(ch == '%')
		{
			ch = *format++;
			switch(ch)
			{
				case 'd':
					a = va_arg(ap,int);
					sprintf(buf,"%d",a);
					puts(a);
					break;
				case 'c':
					c = va_arg(ap,int);
					putchar(c);
					break;
				case 's':
					p = va_arg(ap,char *);
					puts(p);
					break;
				case 'f':
					q = va_arg(ap,double);
					sprintf(buf,"%f",q);
					puts(buf);
					break;
				default: putchar(ch);
			}
		}
	}
	va_end(ap);
}
int main(void)
{
	myprintf("%c\t%s\t%d\t%f\n",'1',"hello",1245,12.5);
	return 0;
}
