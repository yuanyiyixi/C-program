#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>

#define MAX_PATH 1024

void dirwalk(char *dir, void (*fcn)(char *))
{
	char name[MAX_PATH];
	struct dirent *dp;
	DIR *dfd;
	if((dfd = opendir(dir)) == NULL)
	{
		fprintf(stderr, "dirwalk:can't open %s\n", dir);
		return;
	}
	while((dp = readdir(dfd)) != NULL)
	{
		if(strcmp(dp->d_name,".") == 0 || strcmp(dp->d_name,"..") == 0)
			continue;
		else{
			//rmdir(dir);
			(*fcn)(dp->d_name);
		}
	}
	closedir(dfd);
	rmdir(dir);
}
void fsize(char *name)
{
	struct stat stbuf;
	if (stat(name, &stbuf) == -1)
	{
		fprintf(stderr, "fsize: can't access %s\n",name);
		return;
	}
	if ((stbuf.st_mode & S_IFMT) == S_IFDIR)
		dirwalk(name, fsize);
	unlink(name);
}
int main(int argc, char *argv[])
{
	if(argc == 1)
		fsize(".");
	else 
		while(--argc > 0)
			fsize(*++argv);
	return 0;
}
