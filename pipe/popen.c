#include <stdio.h>
#include <unistd.h>
#include <string.h>

int main()
{
	FILE *fpr=NULL,*fpw = NULL;

	char buf[256];
	int ret;
	//创建一个读管道 同时fork一个进程，并exec执行传入的cmd 同时将结果写入此管道
	fpr = popen("cat ./popen.txt","r");
	fpw = popen("grep china","w");
	//fpw 对应标准输出

	while((ret = fread(buf,1,sizeof(buf),fpr))>0){
		fwrite(buf,1,ret,fpw);
	}

	pclose(fpr);
	pclose(fpw);

	return 0;
}
