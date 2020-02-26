#include <stdio.h>

int main(int argc,char *argv[])
{
	FILE *fp;

	int iflag;

	if(argc<=1){
		printf("useage:%s filename\n",argv[0]);
		return 1;
	}

	fp = fopen(argv[1],"a+b");

	if(fp==NULL){
		printf("open file %s failed!\n",argv[1]);
		return 2;
	}

	printf("open file %s succedd!\n",argv[1]);
	iflag = fclose(fp);

	if(iflag==0){
		printf("close file %s succeed!\n",argv[1]);
		return 0;
	}else{
		printf("close file %s failed!",argv[1]);
		return 3;
	}
}
