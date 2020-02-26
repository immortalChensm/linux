#include <stdlib.h>
#include <stdio.h>
int main(void)
{
	int i,j;
	srand((int)time(0));
	for(i=0;i<10;i++){
		j=1+(int)(10.0*rand()/RAND_MAX+1.0);
		printf("%d\n",j);
	}

	return 0;
}
