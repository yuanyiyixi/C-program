#include <stdio.h>

void *memcpy(void *dest,const void *src,size_t n)
{
	char *d = dest + n;
	const char *s = src + n;
	int *di;
	const int *si;
	int r = n % 4;
	while (r--)
		*d--= *s--;
	di = (int *)(d-4);
	si = (const int *)(s-4);
	n /= 4;
	while (n--)
		*di-- = *si--;
	return dest;
}

char buf[16] = { 0x12, 0x34, 0x56, 0x78, 0x99, 0x88, 0x77, 0x66 };
int main(void)
{
	/*int * p;
	p = buf;
	printf("*p = 0x%x\n", *p);
	printf("*p = 0x%x\n", *++p);
	printf("*p = 0x%x\n", *++p);



	printf("buf = 0x%x\n", buf);
	memcpy(buf+1,buf,6);
	p = buf;
	printf("*p = 0x%x\n", *p);
	printf("*p = 0x%x\n", *++p);
	printf("*p = 0x%x\n", *++p);

	return 0;*/

	char s[14]="hello world\n";
	//char *p;
	memcpy(s+1,s,13);
	//p = s+1;
	printf("%s",s);
	return 0;
}
