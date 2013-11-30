#include <stdio.h>
#include <string.h>

int myatoi(const char p[], int pos) {
	int i = 0;
	int val = 0x0;
	for(i = 0; pos >= 0; pos--,i++)
	{
	#if 1	
		switch(p[i])
		{
			case '0': val |= 0x0<<pos*4; break;
			case '1': val |= 0x1<<pos*4; break;
			case '2': val |= 0x2<<pos*4; break;
			case '3': val |= 0x3<<pos*4; break;
			case '4': val |= 0x4<<pos*4; break;
			case '5': val |= 0x5<<pos*4; break;
			case '6': val |= 0x6<<pos*4; break;
			case '7': val |= 0x7<<pos*4; break;
			case '8': val |= 0x8<<pos*4; break;
			case '9': val |= 0x9<<pos*4; break;
			case 'A':
			case 'a':val |= 0xa<<pos*4; break;
			case 'B':
			case 'b':val |= 0xb<<pos*4; break;
			case 'C':
			case 'c':val |= 0xc<<pos*4; break;
			case 'D':
			case 'd':val |= 0xd<<pos*4; break;
			case 'E':
			case 'e':val |= 0xe<<pos*4; break;
			case 'F':
			case 'f':val |= 0xf<<pos*4; break;
			default:
					 return val;
		}
#endif
	}
	return val;
}
int main(void) {
	char str[32];
	int res,pos = 0;
	printf("Please enter :\n");
	scanf("%s", str);
	pos = strlen(str);

	res = myatoi(str,pos-1);//pos 表示输入字符串的位数
	printf("%d\n",res);
	printf("0x%x\n",res);

	return 0;
}

