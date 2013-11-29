#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>

void redirect(char *ps_argv[], int argc);

void mypipe(char *ps_argv[], int n2, int argc)
{
	int fd[2], i, j = 0;
	char *argv[4096];
	char *argv1[4096];

	pid_t pid;

	if (pipe(fd) < 0)
	{
		perror("pipe");
		exit(-1);
	}

	for (i = 0; i < n2; i ++)
		argv[i] = ps_argv[i];
	argv[n2] = NULL;
	for (i = n2 + 1; i < argc; i++ )
		argv1[j++] = ps_argv[i];
	argv1[j] = NULL;

	for (i = 0; i < 2; i++)
	{
		pid = fork(); 
			if(pid < 0)
			{
				perror("fork");
				exit(-1);
			}
		else if(pid == 0)
			break;
	}
	if ((pid == 0) && (i == 0))
	{	
		close(fd[0]);
		dup2(fd[1],STDOUT_FILENO);
		close(fd[1]);
		redirect(argv,n2);
		//execvp(argv[0], argv);
	}
	else if((pid == 0) && (i == 1))
	{
		close(fd[1]);
		dup2(fd[0],STDIN_FILENO);
		close(fd[0]);
		redirect(argv1,j);
		//execvp(argv1[0], argv1);
	}

	close(fd[0]);
	close(fd[1]);
	wait(NULL);
	wait(NULL);
	return ;
}

void redirect(char *ps_argv[], int argc)
{
	char *argv1[4096];
	int n = 0, n1 = 0;
	int i;

	for (i = 0; i < argc; i++)
	{
		if(strcmp(ps_argv[i], ">") == 0)
			n = i;
		else if(strcmp(ps_argv[i], "<") == 0)
			n1 = i;
	}
#if 1
	
	if ((n == 0) && (n1 == 0))
		execvp(ps_argv[0],ps_argv);
	else if((n > 0) && (n1 == 0) )
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
	else if((n1 > 0) && (n == 0))
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
	else if((n1 > 0) && (n > 0))
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
	return ;
}
