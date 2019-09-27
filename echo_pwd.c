#include "header.h"

void echo(char commands[10][1000])
{
	int i=1;
	while(commands[i][0]!='\0')
		printf("%s ",commands[i++]);
	printf("\n");
	return;
}

void pwd()
{
	char pathname[PATH_MAX] = {'\0'};
	getcwd(pathname, sizeof(pathname));
	printf("%s\n",pathname);
}
