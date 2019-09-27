#include "header.h"

void exe(char commands[10][1000],char hd[],int c,int jobs[]){
	
	int i=0;
	int checker=0;
	while(commands[i][0]!='\0'){
		char k=commands[i++][0];
		if(k=='|'||k=='>'||k=='<'){checker=1;break;}
	}
	if(checker)piping_redirection(commands ,hd,c,jobs);
	else cmd(commands , hd , c,jobs);
}