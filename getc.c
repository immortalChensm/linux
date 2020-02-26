#include <stdio.h>
#include <errno.h>

int main(void)
{
	int c;

	printf("pls enter some str\n");

	while((c=getc(stdin))!=EOF){
		if(putc(c,stdout)==EOF){
			perror("output error");
		}
	}

	if(ferror(stdin)){
		perror("input error");
	}

	return 0;
}
