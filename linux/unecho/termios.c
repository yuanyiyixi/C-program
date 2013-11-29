#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <string.h>

int main(void)
{
	struct termios ts,ots;
	char buf[1024];

	tcgetattr(STDIN_FILENO, &ts);//把当前终端接口变量的值写入ts.
	ots = ts;

	/*本地模式设置*/
	ts.c_lflag &= ~ECHO;//如果设置,则启动本地回显.如果没有设置,则除了ECHONL之外,其他以ECHO开头的标记都会失效
	ts.c_lflag |= ECHONL;//如果在标准模式下设置了该标志,即使没有设置ECHO标志,换行符还是会被显示出来.
	tcsetattr(STDIN_FILENO, TCSANOW, &ts);//重新配置终端接口.TCSANOW立即修改

	fgets(buf, sizeof(buf), stdin);
	buf[strlen(buf) - 1] = '\0';
	printf("buf = %s\n", buf);
	
	tcsetattr(STDIN_FILENO, TCSANOW, &ots);//恢复原来的配置

	fgets(buf, sizeof(buf), stdin);
	buf[strlen(buf) - 1] = '\0';
	printf("buf1 = %s\n", buf);

	return 0;
}
