#include <stdio.h>
#include <errno.h>
#include <stdlib.h>

#define MAXLINE 4096

int main(void)
{
	char buf[MAXLINE];
	printf("pls enter some str\n");
	while(fgets(buf,MAXLINE,stdin)!=NULL){
		if(fputs(buf,stdout)==EOF){
			perror("output error");
		}
	}

	if(ferror(stdin)){
		perror("input error");
	}

	exit(0);
}
