#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

int main(void)
{
	unsigned char temps1[]="23";
	unsigned char temps2[]="321K";
	unsigned char temps3[]="-32";

	int temp=0;
	printf("%s\n",temps1);
	temp = atoi(&temps1[0]);
	printf("%d\n",temp);
	printf("%d\n",temp*2);
	printf("%s\n",temps2);

	temp = atoi(&temps2[0]);
	printf("%d\n",temp);
	printf("%s\n",temps3);

	temp = atoi(&temps3[0]);
	printf("%d\n",temp);

	temp = atol(&temps3[0]);
	printf("atol-%d\n",temp);

	temp = atoll(temps3);
	printf("atoll-%d\n",temp);
	return 0;
}
