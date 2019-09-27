#include "header.h"

void pinfo(int pid,char hd[]){
	char tmp1[100] = {'\0'};
    char tmp2[100] = {'\0'};
	char spid[]="";
	sprintf(spid, "%d", pid);
	char path1[1000]="/proc/";
	char path2[1000]="/proc/";
	char path3[1000]="/proc/";
	sprintf(spid, "%d", pid);

	FILE *fp1;
	char status[59];
	strcat(path1,spid);
	strcat(path1,"/stat");
	fp1 = fopen(path1,"r");

	FILE *fp2;
	char memory[59];
	strcat(path2,spid);
	strcat(path2,"/statm");
	fp2 = fopen(path2,"r");

	char exec[1000]={'\0'};
	strcat(path3,spid);
	strcat(path3,"/exe");
	readlink(path3,exec,1000);
	get_tilda(exec,hd);

	if(fp2==NULL||fp1==NULL)printf("PID(%d) DOESNT EXIST\n",pid);

	else{
		fscanf(fp1, "%s %s %s", tmp1, tmp2, status);
	    fscanf(fp2, "%s", memory);
		printf("pid -- %d\n", pid);
	    printf("Process Status -- %s\n", status);
	    printf("memory -- %s {Virtual Memory}\n", memory);
	    printf("Executable Path -- %s\n", exec);	
	}



}