#include "header.h"

void piping_redirection(char commands[10][1000],char hd[],int c,int jobs[]){
	int i=0;int s=0,e=0;
	while(commands[i++][0]!='\0');
	// printf("%d kldfj\n",i);
	strcpy(commands[i],"\0");
	i--;
	strcpy(commands[i],"|");
	i=0;
	// while(commands[i][0]!='\0')printf("%s\n",commands[i++] );;

	int stdout = dup(1);
	int stdin = dup(0);
	int fd[2];
	pipe(fd);
	int pnt=0;
	int start[10];int end[10];
	while(commands[i][0]!='\0'){
		if(!strcmp(commands[i],"|")){
			e=i-1;
			start[pnt]=s;
			end[pnt++]=e;			
			s=i+1;
		}
		i++;	
	}
	
	// for(int i=0;i< pnt ;i++){
	// 	printf("%d %d\n",start[i],end[i] );
	// }
	
	int ii=1;
	i=0;
	while(commands[i][0]!='\0'){
		if(!strcmp(commands[i],"|"))
		{
				// printf("fk,nfksfjnekfnwkelfnnfk\n");
			// printf("%d\n", i);
			pid_t pid1 = fork();

			if(pid1==0)
			{
				// printf("fk,nfk\n");
				dup2(fd[1], 1);
				close(fd[0]);
				redirect(commands,start[ii-1],end[ii-1],hd,c,jobs);
				_exit(0);
			}

			pid_t pid2 = fork();

			if(pid2==0)
			{
				dup2(fd[0], 0);
				close(fd[1]);
				redirect(commands,start[ii],end[ii],hd,c,jobs);
				_exit(0);
			}

			dup2(stdin, 0);
			dup2(stdout, 1);
			close(fd[0]);
			close(fd[1]);
			wait(NULL);
			wait(NULL);
			return 0;

			ii++;
		}
		i++;
	}
		// redirect(commands,s,e,hd,c);
}