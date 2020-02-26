#include <stdio.h>
#include <stdlib.h>

void jobs()
{
	static int i=0;
	switch(i){
		case 0:
			printf("看见美女\n");
			i=1;
			return ;
			case 1:
				printf("脱掉裤子\n");
				i = 2;
				return ;
				case 2:
					printf("准备起抢\n");
					i=3;
					return ;
					case 3:
						printf("然后洗澡\n");
						i++;
						return ;
	}
}
int main()
{
	jobs();

	int j=0;
	for(j;j<10;j++){
		printf("%d\n",j);
	}

	jobs();
	jobs();
	jobs();
	jobs();

	return 0;
}
