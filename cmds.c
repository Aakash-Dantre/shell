#include "header.h"

void cmd(char commands[10][1000], char hd[],int c,int jobs[]) {
		
	char first[100];
	strcpy(first,commands[0]);
	// if(commands[0][0]=='\0')return;
	
	if(!strcmp(first,"exit"))exit(0);		

	else if(!strcmp(first,"echo"))echo(commands);

	else if(!strcmp(first,"ls")){
		int a=0;int l=0;   // initialize a , l flags
		char dire[10][1000]={'\0'};int d=0;
		int i=1;
		while(commands[i][0]!='\0'){
			if(commands[i][0]=='-'){
				if(commands[i][2]=='\0'){
    	        	if(commands[i][1]=='a')a=1;
        	    	if(commands[i][1]=='l')l=1;
        	    }
			
    	        if(commands[i][3]=='\0'){
                 	if(commands[i][1]=='a' && commands[i][2]=='l')a=1,l=1;
                 	if(commands[i][1]=='l' && commands[i][2]=='a')a=1,l=1;
                }
            }
            else{
            	strcpy(dire[d++],commands[i]);
            }
            i++;	
		}
		i=0;
		if(d==0)strcpy(dire[0],".\0");
		if(a==0&&l==0)ls(dire,hd);
		else if(a&&l)lsal(dire,hd);
		else if(a==1&&l==0)lsa(dire,hd);
		else lsl(dire,hd);	
	}

	else if(!strcmp(first,"cd")){
		if(c>2)printf("cd : invalid syntax\n");
		else{
			if(c==1)strcpy(commands[1],"~\0");
		 cd(commands[1],hd);
		}
	}
	
	else if(!strcmp(first,"pwd"))pwd();
	
	else if(!strcmp(first,"pinfo")){
		if(commands[1][0]=='\0')pinfo(getpid(),hd);
		else pinfo(atoi(commands[1]),hd);
	}
	
	else if(!strcmp(first,"kill"))killandprint(atoi(commands[1]),jobs);
	else if(!strcmp(first,"jobs"))job(jobs);
	else if(!strcmp(first,"overkill"))overkill(jobs);
	else if(!strcmp(first,"kjob"))kjobs(atoi(commands[1]),atoi(commands[2]),jobs);
	
	else if(!strcmp(first,"fg"))fg(atoi(commands[1]),jobs);
	else if(!strcmp(first,"bg"))bg(atoi(commands[1]),jobs);
	else if(!strcmp(first,"setenv"))setenvl(commands);
	else if(!strcmp(first,"unsetenv"))unsetenvl(commands);
	
	else if(!strcmp(first,"cronjob"))corn(commands,hd,jobs);
	else {

		// printf("thsii  %s\n",commands[0] );
		sys(commands,hd,jobs); 
	}
	
}