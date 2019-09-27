#include "header.h"

void cd(char dir[1000],char hd[]){
	if(dir[0]=='~')
		convert_tilda(dir,hd);
	int x=chdir(dir);
	if(x < 0)
		printf("cd: %s: No such directory\n", dir);
}