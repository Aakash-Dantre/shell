#include "header.h"


void ls(char dire[10][1000], char hd[]){
	struct dirent **namelist;
   int n;int i=0;
   while(dire[i][0]!='\0'){
   	   if(dire[i][0]=='~')convert_tilda(dire[i],hd);

	   n = scandir(dire[i], &namelist, NULL, alphasort);
	   if (n == -1) {
	       perror("scandir");
	   }
	   else{
	   	   printf("%s  : \n\n",dire[i]);	
		   while (n--) {
		       if(namelist[n]->d_name[0]!='.')
		       printf("%s\n", namelist[n]->d_name);
		       free(namelist[n]);
		   }
		   free(namelist);
		   }
	   i++;

	}	
}

void lsal(char dire[10][1000], char hd[]){
struct dirent **namelist;
   int n;int i=0;
   char name[1000];
   while(dire[i][0]!='\0'){	
   	   if(dire[i][0]=='~')convert_tilda(dire[i],hd);

	   n = scandir(dire[i], &namelist, NULL, alphasort);
	   if (n == -1) {
	       perror("scandir");
	   }
	   else{
	   		struct passwd *pw;
	   		struct group *gp;
			pw = getpwuid(geteuid());
			gp = getgrgid(getgid());

	   	   
	   	   printf("%s  : \n\n ",dire[i]);	
		   while (n--){
		   		int dir=0,x=0;
		   		char time[50] = {'\0'};
		   		struct stat fileStat;
		   		strcpy(name,namelist[n]->d_name);
		   		if(stat(name,&fileStat) < 0)    
        		return 1;
				//for time
        		strftime(time, sizeof(time), "%b %d %H:%M", localtime(&fileStat.st_mtime));     
        		if(S_ISDIR(fileStat.st_mode))dir=1,printf("d");
        		else printf("-"); 
			    printf( (fileStat.st_mode & S_IRUSR) ? "r" : "-");
			    printf( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
			    if(fileStat.st_mode & S_IXOTH)x=1,printf("x");
        		else printf("-");
	
			    printf( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
			    printf( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
			    if(fileStat.st_mode & S_IXOTH)x=1,printf("x");
        		else printf("-");
	
			    printf( (fileStat.st_mode & S_IROTH) ? "r" : "-");
			    printf( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
			    if(fileStat.st_mode & S_IXOTH)x=1,printf("x");
        		else printf("-");
	

			    printf(" %d %s %s %d %s ",(int)fileStat.st_nlink,pw->pw_name,gp->gr_name,(int)fileStat.st_size,time);

			    //if dir=1 blue, if x=1 green else white
			    if(dir)printf("\e[1;34m%s\e[0m",name );
			    else{
			    	if(x)printf("\e[1;32m%s\e[0m",name );
			    	else printf("%s",name );
			    }

			    printf("\n");		   			
		       free(namelist[n]);
		   }
		   free(namelist);
		}
	   i++;

	}

}
void lsl(char dire[10][1000], char hd[]){
struct dirent **namelist;
   int n;int i=0;
   char name[1000];
   while(dire[i][0]!='\0'){	
   	   if(dire[i][0]=='~')convert_tilda(dire[i],hd);

	   n = scandir(dire[i], &namelist, NULL, alphasort);
	   if (n == -1) {
	       perror("scandir");
	   }
	   else{
	   		struct passwd *pw;
	   		struct group *gp;
			pw = getpwuid(geteuid());
			gp = getgrgid(getgid());

	   	   
	   	   printf("%s  : \n\n ",dire[i]);	
		   while (n--){
		   	
		   		int dir=0,x=0;
		   		char time[50] = {'\0'};
		   		struct stat fileStat;
		   		strcpy(name,namelist[n]->d_name);
		   		if(stat(name,&fileStat) < 0)    
        		return 1;
					if(name[0]!='.'){	        	
					//for time
	        		strftime(time, sizeof(time), "%b %d %H:%M", localtime(&fileStat.st_mtime));     
	        		if(S_ISDIR(fileStat.st_mode))dir=1,printf("d");
	        		else printf("-"); 
				    printf( (fileStat.st_mode & S_IRUSR) ? "r" : "-");
				    printf( (fileStat.st_mode & S_IWUSR) ? "w" : "-");
				    if(fileStat.st_mode & S_IXOTH)x=1,printf("x");
	        		else printf("-");
		
				    printf( (fileStat.st_mode & S_IRGRP) ? "r" : "-");
				    printf( (fileStat.st_mode & S_IWGRP) ? "w" : "-");
				    if(fileStat.st_mode & S_IXOTH)x=1,printf("x");
	        		else printf("-");
		
				    printf( (fileStat.st_mode & S_IROTH) ? "r" : "-");
				    printf( (fileStat.st_mode & S_IWOTH) ? "w" : "-");
				    if(fileStat.st_mode & S_IXOTH)x=1,printf("x");
	        		else printf("-");
		

				    printf(" %d %s %s %d %s ",(int)fileStat.st_nlink,pw->pw_name,gp->gr_name,(int)fileStat.st_size,time);

				    //if dir=1 blue, if x=1 green else white
				    if(dir)printf("\e[1;34m%s\e[0m",name );
				    else{
				    	if(x)printf("\e[1;32m%s\e[0m",name );
				    	else printf("%s",name );
				    }

				    printf("\n");		   			
			       free(namelist[n]);
			   }
		   }
		   free(namelist);
		}
	   i++;

	}
}

void lsa(char dire[10][1000], char hd[]){
   struct dirent **namelist;
   int n;int i=0;
   while(dire[i][0]!='\0'){	
   	   if(dire[i][0]=='~')convert_tilda(dire[i],hd);

	   n = scandir(dire[i], &namelist, NULL, alphasort);
	   if (n == -1) {
	       perror("scandir");
	   }
	   else{
	   	   printf("%s  : \n\n ",dire[i]);	
		   while (n--) {
		       printf("%s\n", namelist[n]->d_name);
		       free(namelist[n]);
		   }
		   free(namelist);
		}
	   i++;
	}
}
