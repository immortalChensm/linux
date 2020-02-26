#include <stdio.h>
#include <string.h>

int main(void)
{
	char *temps1 = "hello world!";
	char temps2[20];

	char *temp;
	temp = memccpy(temps2,temps1,'0',20);
	if(temp){
		*temp='\0';
		printf("char found:%s\n",&temps2[0]);
	}else{
		printf("char not found.\n");
	}

	//printf("%s\n",temps1);
	//printf("%s\n",temps1[0]);
	//printf("%s\n",temps2);
	//printf("%s\n",&temps2[1]);


	char str[] = "chinaandjapanese";
	printf("%s\n",str);
	printf("%s\n",&str[0]);
	printf("%s\n",str+2);
	return 0;
}
