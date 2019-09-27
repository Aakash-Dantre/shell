#include "header.h"

int current_pid;
int jobs[1000];


void signalhandlerz(int sig){	
	signal(SIGTSTP,signalhandlerz);
	jobs[jobs[0]]=current_pid;           // add the pid of current process to jobs
	jobs[0]++;
}

void signalhandlerc(int sig){	
	signal(SIGINT,signalhandlerc);
	fflush(stdout);
}

int main(int argc, char const *argv[])
{
	
	char hd[1000];getcwd(hd,1000);
	for(int i=0;i<1000;i++)jobs[i]=-1;
	jobs[0]=1;       // tell the counter
	int h=0;
	int i=1;
	int hptr=0;
	signal(SIGINT, signalhandlerc);             // for control c implementation
	signal(SIGTSTP, signalhandlerz);            // for control z implementation

	while(1){

		print(hd);    // prints header
		// for(int i=1;i<jobs[0];i++)printf("%d\n",jobs[i] );
		char input[1000],his[20][1000];  // input 1000 bytes
		char sep[10][1000];

		//takes input
		fgets(input,1000,stdin);
		i=0;int cntu=0,cntd=0;
		while(1){              // stores no. of upper key
			if(input[i]==27&&input[i+1]==91&&input[i+2]==65){
				i+=3;
				cntu ++;
				continue;
			}	
			break;
		}
		i=0;
		while(1){              // stores no. of lower key
			if(input[i]==27&&input[i+1]==91&&input[i+2]==66){
				i+=3;
				cntd ++;
				continue;
			}
			break;
		}
		i=0;int cnt=cntu-cntd;
	
		if(cnt==0)strcpy(his[(hptr++)%20],input);//history
		
		if(cnt>0){strcpy(input,his[hptr-cnt] );
		print(hd);printf("%s",input );}

		char* token;int to=0;
		token = strtok(input, ";");  // if diff command are there we wil first do for one
		while(token != NULL)
		{
			strcpy(sep[to], token);
			to++;
			token = strtok(NULL, ";");
		}

		token = NULL;
		int length = to;
		int c,q,j;char ptr;
		for(int no=0;no<length;no++)
		{	
			char inpu[1000];strcpy(inpu, sep[no]);
			int len=strlen(inpu);
			inpu[len-1]=32;  
			inpu[len]='\0';

			int i=0;
			while(inpu[i]=='\t'||inpu[i]==32)i++;

			char commands[10][1000]={'\0'};
			c=0;q=0;j=0;
			for(;i<len;i++){
				ptr=inpu[i];
				if(ptr=='\''||ptr=='\"'){q++;continue;}
				if(q>0){
					if(q==2){q=0;c++;j=0;break;}
					else	
						commands[c][j++]=ptr;
				}
				else{
					if(ptr!='\t'&&ptr!=32)commands[c][j++]=ptr;
					else{
					 	c++,j=0;
					 	while(inpu[i+1]=='\t'||inpu[i+1]==32)i++;
					}
				}	
			}
			if (commands[0][0]=='\0');
			else if (!strcmp(commands[0],"history"))
			{
				if(commands[1][0]=='\0')
				hist(10,hptr,his);
				else hist(atoi(commands[1]),hptr,his);
				/* code */
			}
			else exe(commands,hd,c,jobs);


		}		
		
	}
}