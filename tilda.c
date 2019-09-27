#include "header.h"
//convert absolute to relative
void get_tilda(char cd[],char hd[]){
		int c=strlen(cd);
		int h=strlen(hd);
		
		int count_cd=0;int count_hd=0;
		for(int i=0;i<c;i++)if(cd[i]=='/')count_cd++;
		for(int i=0;i<h;i++)if(hd[i]=='/')count_hd++;

		if(!strcmp(cd,hd))strcpy(cd,"~");
		if(count_cd > count_hd){
			char rel[1000];
			int p=0;rel[p++]='~';
			for(int i=h;i<c;i++)rel[p++]=cd[i];
			strcpy(cd,rel);
		}
}

//convets relative to absolute
void convert_tilda(char cd[],char hd[]){
	char abs[1000];
	int h=strlen(hd);
	int c=strlen(cd);
	// printf("%s\n",cd );
	// printf("%s\n",hd );
	int i=0;
	if(!strcmp(cd,"~"))strcpy(cd,hd);
	else{
		for(i=0;i<h;i++)abs[i]=hd[i];
		for(int j=1;j<c;j++,i++)abs[i]=cd[j];
		abs[h+c-1]='\0';	
		strcpy(cd,abs);	
	}
}