#include "header.h"

void job(int jobs[]){
	int cnt=1;
	for(int i=1;i<jobs[0];i++){
		if(jobs[i]!=-1){
			if(kill(jobs[i],0)==0){
				char tmp[100] = {'\0'};
	        	char name[100] = {'\0'};
	 			char status[10]={'\0'};       
				char path[]="";
				sprintf(path, "/proc/%d", jobs[i]);
				FILE *fp1;
				strcat(path,"/stat");
				fp1 = fopen(path,"r");

				fscanf(fp1, "%s %s %s", tmp, name, status);

				if(!strcmp(status, "Z"))jobs[i]=-1;

				else{
					printf("[%d] ",cnt );cnt++;
					printf("%s   ",name );
					if(!strcmp(status, "T"))
		            printf("Stopped  ");
		        	else
		            printf("Running  ");
		        	printf("%s\n",tmp );
		        }
		    }
		    else jobs[i]=-1;
		}
	}	
}