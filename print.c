#include "header.h"

void print(char hd[1000]){
	char cd[1000];
	char host[100];gethostname(host,100);
	getcwd(cd,1000);
	struct passwd *pw;
	pw = getpwuid(geteuid());
	get_tilda(cd,hd);
	if(pw)
	printf("\x1b[1;32m<%s@%s:\x1b[1;34m%s>\x1b[0m ",pw->pw_name, host, cd);
	else
	{
		printf("Some error occurred in getting username\n");
		return 0;
	}
}