#include "header.h"

void killandprint(int pid,int jobs[]){
	char spid[1000];
	char check[1000];
	sprintf(check,"/proc/%d",pid);
	DIR* dir = opendir(check);
	if(dir){
		sprintf(spid, "/proc/%d/status", pid);
		char name[100];
		char tmp[10];
		FILE *fps;
		fps=fopen(spid,"r");
		fscanf(fps,"%s %s",tmp,name);
		printf("%s\n",name );
		if(kill(pid,9)==-1){
			printf("error occured while killing\n");
		
			perror("kill");
		}
		else{
			for(int i=1;i<jobs[0];i++)if(jobs[i]==pid)jobs[i]=-1;
			printf("%s(%d) have exited sucessfully\n",name ,pid );
		}
	}
	else{
		printf("pid doesnt exist\n" );
	}
}