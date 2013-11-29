#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/inotify.h>
#include <unistd.h>
#include <string.h>

void daemonize(char argv[])
{
	pid_t pid;
	int fd;
	int save_fd;
	if ((pid = fork()) < 0)
	{
		perror("fork");
		exit(-1);
	}
	else if(pid > 0)
		exit(0);

	setsid();
	if(chdir("/") < 0)
	{
		perror("chdir");
		exit(-1);
	}
	close(0);
	fd = open("/home/akaedu/filechange.log", O_RDWR | O_CREAT | O_APPEND,0666);
	dup2(fd, 1);
	dup2(fd, 2);

	int fd1, wd, len, i = 0;
	char buf[1024], buffer[1024];
	if((fd1 = inotify_init()) < 0)//初始化,创建一个 inotify 实例的系统调用,并返回一个指向该实例的文件描述符.
	{
		perror("inotify_init");
		exit(-1);
	}
	wd = inotify_add_watch(fd1, argv, IN_ALL_EVENTS);//增加对文件或者目录的监控,并指定需要监控哪些事件.标志用于控制是否将事件添加到已有的监控中,是否只有路径代表一个目录才进行监控,是否要追踪符号链接,是否进行一次性监控,当首次事件出现后就停止监控. 
	while(len = read(fd1, buf, sizeof(buf)))
	{
		i = 0;
		while(i < len)
		{
			struct inotify_event *event = (struct inotify_event *) &buf[i];
			if ( event->len ) {
				if ( event->mask & IN_CREATE ) {
					if ( event->mask & IN_ISDIR ) {
						sprintf(buffer,"The directory %s was created.\n", event->name );       
					}
					else {
						sprintf(buffer, "The file %s was created.\n", event->name );
					}
					write(fd, buffer, strlen(buffer));
				}
				else if ( event->mask & IN_DELETE ) {
					if ( event->mask & IN_ISDIR ) {
						sprintf(buffer, "The directory %s was deleted.\n", event->name );       
					}
					else {
						sprintf(buffer, "The file %s was deleted.\n", event->name );
					}
					write(fd, buffer, strlen(buffer));
				}
				else if ( event->mask & IN_MODIFY ) {
					if ( event->mask & IN_ISDIR ) {
						sprintf(buffer, "The directory %s was modified.\n", event->name );
					}
					else {
						sprintf(buffer, "The file %s was modified.\n", event->name );
					}
					write(fd, buffer, strlen(buffer));
				}
			}
			i += sizeof(struct inotify_event) + event->len;
		}

	}
	( void ) inotify_rm_watch( fd1, wd );
	( void ) close( fd1 );
}
int main(int argc, char *argv[])
{
	if (argc < 2)
	{
		printf("./a.out dir");
		exit(-1);
	}

	daemonize(argv[1]);
	return 0;
}
