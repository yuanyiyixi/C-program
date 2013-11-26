#include <stdio.h>
#include <string.h>

int load(char *file)
{
	printf("./mydict ");
	return load_file(file);
}

int search(char *argv)
{
		search_word(argv);
		return 0;
}

/*int add(char *buf)
{
	fp = fopen("myadd.txt","w");
	if(fp == NULL)
	{
		perror(fopen);
		exit(-1);
	}
	fwrite(buf, 1, sizeof(buf),fp);
	fclose(fp);

	return 0;
}*/
