#include "header.h"

void setenvl(char commands[10][1000])
{
    int total_commands = 0;
    while(commands[total_commands][0] != '\0')total_commands ++;
    
    if(total_commands == 1 || total_commands > 3)
    {
        perror("Usage: setenv <var> <value> or setenv <var>\n");
        return;
    }
    if(commands[2][0] == '\0')
        strcpy(commands[2],"");
    setenv(commands[1], commands[2], 1);
    return;
}

void unsetenvl(char commands[10][1000])
{
    int total_commands = 0;
    while(commands[total_commands] != NULL)
        total_commands ++;
    if(total_commands != 2)
    {
        perror("Usage: unsetenv <var>\n");
        return;
    }
    unsetenv(commands[1]);
    return;
}