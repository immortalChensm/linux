#include <stdio.h>

int main(int argc,char *argv[])
{
	int temp,seektemp,i,j;
	FILE *fp;

	char wbuf[17] = "this is a test!\r\n";
	if(argc!=2){
		printf("run error!\n");
		return 1;
	}
	fp = fopen(argv[1],"ab");
	for(i=0;i<10;i++){
		j=sizeof(wbuf)*(i+1);
		printf("pos=%ld\n",ftell(fp));
		fseek(fp,j,SEEK_SET);
		temp = fputs(wbuf,fp);
	}
	fclose(fp);
	//fflush(fp);
	return 0;
}
