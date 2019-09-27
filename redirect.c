#include "header.h"
#include <unistd.h> 
#include <fcntl.h> 

void redirect(char commands[10][1000],int s,int e,char hd[],int c,int jobs[]){
	int out=0;int in=0;int ip=0,o=0;char outfile[20];char infile[20];int ap=0;
	// for(int i=s;i<=e;i++);       // checking output redirection
	// {
	// 	if(!strcmp(newcmds[i],">")){
	// 		out=1;
	// 		strcpy(outfile,newcmds[i+1]);
	// 		int fdout=open(outfile,O_WRONLY | O_CREAT , 0777);
			
	// 		int save= dup(1);

	// 		dup2(fdout,1);
	// 		newcmds[]
	// 		exe(newcmds,hd,c);

	// 		close(fdout);

	// 		dup2(save,1);
	// 	}
	// }
	int pt=0;
	char newcmds[10][1000]={'\0'};
	for(int i=s;i<=e;i++){
		strcpy(newcmds[pt++],commands[i]);
	}
	strcpy(newcmds[pt],"\0");

	for(int i=s;i<=e;i++){
		if(!strcmp(newcmds[i],"<")){
			strcpy(infile,newcmds[i+1]);
			in++;ip=i;
		}
		if(!strcmp(newcmds[i],">>")){
			strcpy(outfile,newcmds[i+1]);
			ap++;out++;o=i;
		}
		if(!strcmp(newcmds[i],">")){
			strcpy(outfile,newcmds[i+1]);
			out++;o=i;
		}
	}

	int stdin=dup(0);
	int stdout=dup(1);
	int fdin;
	int fdout;

	if(in) // input check kiya, if yes, stdin ko redirect kiya
	{
		newcmds[ip][0]='\0';
		fdin=open(infile,O_RDONLY);
		if(fdin < 0){
			perror("");   // if file dont exist
			exit(0);
		}
		dup2(fdin,0);
	}
	if(out) // output check kiya, if yes, stdout ko redirect kiya
	{	
		// printf("lol\n");
		// printf("%d\n",ap );
		newcmds[o][0]='\0';
		fdout= open(outfile, O_WRONLY | O_CREAT , 0644);
		if(ap)lseek(fdout,0,SEEK_END);    //     case of appending
		dup2(fdout,1);
	}

	exe(newcmds,hd,c,jobs);
	
	if(in)
	{
		dup2(stdin,0);
	}
	if(out)
	{
		dup2(stdout,1);
		close(fdout);	
	}

}	