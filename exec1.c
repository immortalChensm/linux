#include <stdio.h>

int main(int argc,char *argv[],char *envp[])
{
	printf("this is argc %d\n",argc);
	printf("this is argv\n");

	while(*argv){
		printf("%s\n",*(argv++));
	}

	printf("this is envp\n");

	while(*envp){
		printf("%s\n",*(envp++));
	}

	return 0;
}
