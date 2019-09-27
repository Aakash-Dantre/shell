#include "header.h"

void corn(char commands[10][1000],char hd[],int jobs[]){
	int i=1;int c=0,t=0,p=0;int cin=0,pin=0,tin=0;
	while(commands[i][0]!='\0'){
		if(commands[i][0]=='-'){
			if(commands[i][1]=='c'&&(!c))c=1,cin=i+1;
			if(commands[i][1]=='t'&&(!t))t=1,tin=i+1;
			if(commands[i][1]=='p'&&(!p))p=1,pin=i+1;
		}
		i++;
	}
	if(!c)printf("please enter commands using -c flag\n");
	else{
		if(!t)printf("please enter time interval using -t flag\n");
		else{
			if(!p)printf("please enter -p flag\n");
			else{
				char com[10][1000]={'\0'};
				i=cin;
				while(i!=tin-1){
					strcpy(com[i-cin],commands[i]);
					i++;
				}
				
				int t=0;
				//printf("%s \n %s \n %s \n",commands[cin],commands[tin],commands[pin]);
				// creates a child process that will keep on calling that command after some interval
				
				int pid=fork();
				if(pid==0){
					int time=atoi(commands[tin]);
					int loop=atoi(commands[pin])/ time;
					while(loop--){
						
						sleep(time);
						
						cmd(com , hd,5, jobs);

						print(hd);  //prints header

					}
				}
			}
		}
	}	
}