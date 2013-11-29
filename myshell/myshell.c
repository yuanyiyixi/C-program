#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

extern void parse (char *buf, int *argc, char *argv[]);
extern void mypipe (char *ps_argv[], int n2, int argc);
extern void redirect (char *ps_argv[], int argc);

int main(void)
{
	char *ps_argv[4096];
	char buf[4096], str[4096];;
	pid_t pid;
	int save_fd, save_fd1, n;
	int i, argc;

	save_fd = dup(STDOUT_FILENO);
	save_fd1 = dup(STDIN_FILENO);

	while(1)
	{
		n = -1;
		dup2(save_fd, STDOUT_FILENO);
		dup2(save_fd1, STDIN_FILENO);

		write(STDOUT_FILENO, "myshell$",8);
		fgets(buf, sizeof(buf), stdin);
		strcpy(str, buf);
		if(strcmp(buf, "exit\n") == 0)
			return 0;
		parse(buf, &argc, ps_argv);
		pid = fork();

		if(pid < 0)
		{
			perror("fork");
			exit(-1);
		}
		else if(pid == 0)
			break;
		else 
			wait(NULL);
	}
	for (i = 0; i < argc; i++)
		if(strcmp(ps_argv[i], "|") == 0)
			n = i;
	if(n == -1)
		redirect(ps_argv,argc);
	else
		mypipe(ps_argv,n,argc);
	return 0;
}
#if 0
for (i = 0; i < argc; i++)
{
	if(strcmp(ps_argv[i], ">") == 0)
		n = i;
	else if(strcmp(ps_argv[i], "<") == 0)
		n1 = i;
	else if(strcmp(ps_argv[i], "|") == 0)
	{
		n2 = i; 
		//mypipe(ps_argv,n2,argc);
	}
}
#endif
#if 0
if(n2 > 0)
	mypipe(ps_argv,n2,argc);


if ((n == 0) && (n1 == 0) && (n2 == 0))
	execvp(ps_argv[0],ps_argv);
else if((n > 0) && (n1 == 0) && (n2 == 0))
{
	for (i = 0; i < n; i++)
		argv1[i] = ps_argv[i];
	argv1[n] = NULL;

	int fd;
	fd = open(ps_argv[n + 1], O_WRONLY | O_CREAT, 0666);
	if(fd < 0)
	{
		perror("open");
		exit(-1);
	}
	dup2(fd, STDOUT_FILENO);
	close(fd);
	execvp(argv1[0],argv1);
}
else if((n1 > 0) && (n == 0) && (n2 == 0))
{
	for (i = 0; i < n1; i++)
		argv1[i] = ps_argv[i];
	argv1[n1] = NULL;

	int fd;
	fd = open(ps_argv[n1 + 1], O_RDONLY);
	if(fd < 0)
	{
		perror("open");
		exit(-1);
	}
	dup2(fd, STDIN_FILENO);
	close(fd);
	execvp(argv1[0],argv1);
}
else if((n1 > 0) && (n > 0) && (n2 == 0))
{
	for (i = 0; (i < n1) || (i < n); i++)
		argv1[i] = ps_argv[i];
	argv1[i] = NULL;

	int fd, fd1;
	fd = open(ps_argv[n1 + 1], O_RDONLY);
	fd1 = open(ps_argv[n + 1], O_WRONLY | O_CREAT, 0666);

	if(fd < 0 || fd1 < 0)
	{
		perror("open");
		exit(-1);
	}
	dup2(fd, STDIN_FILENO);
	dup2(fd1, STDOUT_FILENO);
	close(fd);
	close(fd1);
	execvp(argv1[0],argv1);
}
#endif
