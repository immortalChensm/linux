#include <stdio.h>
#include <ctype.h>
int main(void)
{
	char c;
	while((c=getchar())!='\n'){
		if(isupper(c)){
			printf("%c is an uppercase char\n",c);
		}
	}

	return 0;
}
