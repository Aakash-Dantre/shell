#include "header.h"

void hist(int number,int ptr,char his[20][1000]){
	if(ptr>=number){
		ptr=ptr-number;
		for(int i=0;i<number;i++)printf("%d - %s\n",i+1,his[ptr+i]);
	}
	else{
		ptr=20+ptr-number;
		for(int i=0;i<number;i++)printf("%d - %s\n",i+1,his[(ptr+i)%20]);

	}
}