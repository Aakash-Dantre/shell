 #include "header.h"
extern int current_pid;

void sig_handler(int signum) 
{
	int child_status=0;
	int pid = waitpid(-1, &child_status, WNOHANG);
	// if(pid > 0)
	// {
	// 	printf("\nProcess %s with pid %d exited with exit status: %d\n", backProc[findProcNum(pid)], pid, child_status);
	// }
}

void sys(char commands[10][1000],char hd[],int jobs[]){
	int i=0;
	while(commands[i++][0]!='\0');	
	i=i-2;
	//background process
	if(!strcmp(commands[i],"&\0")){

		int p=fork();
		if(p){
			jobs[jobs[0]]=p;
			jobs[0]++;
		}
			
		if(p==0){
			int c=1;int i=1;
			while(commands[i++][0]!='\0')c++;c--;
			char ** ptr= (char **)malloc(sizeof(char *)*10);
			for(int i=0;i<c;i++) {
				ptr[i] = malloc(1000);
				strcpy(ptr[i], commands[i]);
			}
			ptr[c] = NULL;

			//changing group 	
			setpgid(0,0);
			execvp(ptr[0], ptr);
			printf("shell : no such command\n");  // error handling	 
			free(ptr);
			exit(0);
		}
		else 
		{
			signal(SIGCHLD,sig_handler);
		}

	}
	// foreground process
	else{
		int p=fork();
		if(p==0){
			int c=1;int i=1;
			while(commands[i++][0]!='\0')c++;
			char ** ptr= (char **)malloc(sizeof(char *)*10);
			for(int i=0;i<c;i++) {
				ptr[i] = malloc(1000);
				strcpy(ptr[i], commands[i]);
			}
			ptr[c] = NULL;
			execvp(ptr[0], ptr);
			printf("shell : no such command\n");  // error handling
			free(ptr);
			exit(0);
		}
		else{
			current_pid=p;
			int status;
			waitpid(p, &status ,WUNTRACED);
		}
	}

}