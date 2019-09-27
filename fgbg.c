#include "header.h"

void fg(int jn,int jobs[])
{
    int cntr = 1;
    int status;
    printf("job is %d\n",jn );
    for(int i = 1 ; i <= jobs[0] ; i++)
    {
        if(jobs[i]!=-1)
        {	
        	printf("%d\n",jobs[i] );
	        if(cntr == jn)
	        {
	            int pid=jobs[i];

	            if(getpgid(pid)!=getpid())tcsetpgrp(0,pid);
	            else tcsetpgrp(pid,pid);

	            kill(pid,SIGCONT);
	            waitpid(pid,&status,WUNTRACED);
	            signal(SIGTTOU,SIG_IGN);


	            int stdin_pgid;
	            stdin_pgid=tcgetpgrp(STDIN_FILENO);
	            if(stdin_pgid==-1)printf("could not get pgid for stdin.n\n");

	            else if(tcsetpgrp(STDIN_FILENO,getpid())==-1){
	                printf("could not set pgid.n\n");
	            }
	            signal(SIGTTOU,SIG_DFL);
	            break;
	        }
        	cntr++;
    	}
    }
    if(cntr != jn)
        perror("Invalid jobnumber\n");
    return;
}

void bg(int jn,int jobs[]){
    int cntr = 1;
    for(int i = 1; i < 1000 ; i++)
    {
        if(jobs[i] == -1)
            continue;
        if(cntr == jn)
        {
            int status;
            kill(jobs[i], SIGCONT);
            break;
        }
        cntr++;
    }
    if(cntr != jn)
        perror("Invalid jobnumber\n");
    return;
}





