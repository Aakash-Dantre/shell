
#ifndef DEFINITIONS
#define DEFINITIONS

void cmd(char commands[10][1000], char hd[],int c,int jobs[]);
void echo(char commands[10][1000]);
void ls(char dire[10][1000], char hd[]);
void lsa(char dire[10][1000], char hd[]);
void lsal(char dire[10][1000], char hd[]);
void lsl(char dire[10][1000], char hd[]);
void cd(char dir[1000],char hd[]);
void convert_tilda(char cd[],char hd[]);
void get_tilda(char cd[],char hd[]);
void pwd();
void pinfo(int pid,char hd[]);
void hist(int number,int ptr,char his[20][1000]);
void sys(char commands[10][1000],char hd[],int jobs[]);
void killandprint(int pid,int jobs[]);
void corn(char commands[10][1000],char hd[],int jobs[]);
void print(char hd[]);
void piping_redirection(char commands[10][1000],char hd[],int c,int jobs[]);
void redirect(char commands[10][1000],int s,int e,char hd[],int c,int jobs[]);
void exe(char commands[10][1000],char hd[],int c,int jobs[]);
void job(int jobs[]);
void overkill(int jobs[]);
void fg(int jn,int jobs[]);
void bg(int jn,int jobs[]);

void setenvl(char command[10][1000]);
void unsetenvl(char command[10][1000]);
void kjobs(int j,int sig,int jobs[]);




#endif
