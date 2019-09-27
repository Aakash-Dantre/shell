#include "header.h"

void overkill(int jobs[]){
	for(int i=1;i< jobs[0];i++){
		if(jobs[i]!=-1){
			char spid[1000	];
			sprintf(spid, "/proc/%d/status", jobs[i]);
			char name[100];
			char tmp[10];
			FILE *fps;
			fps=fopen(spid,"r");
			fscanf(fps,"%s %s",tmp,name);
			
			if(kill(jobs[i],9)==-1){
				printf("error occured while killing\n");
				perror("kill");
			}
			else{
				printf("%s(%d) have exited sucessfully\n",name ,jobs[i] );
				jobs[i]=-1;
			}
		}
	}
}

