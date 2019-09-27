#include "header.h"

void kjobs(int j,int sig,int jobs[]){
	int cntr = 1;
    for(int i = 1;i < 1000; i++)
    {
        if(jobs[i] == -1)
            continue;
        if(cntr == j)
        {
            int x = kill(jobs[i], sig);
            if(x < 0)
            {
                printf("Invalid signal number\n");
                return;
            }
            else jobs[i]=-1;
            break;
        }
        cntr++;
    }
    if(cntr != j)
        printf("No such job number exists\n");
}