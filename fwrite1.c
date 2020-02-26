#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct person{
	short int age;
	unsigned char name[20];
	unsigned char email[50];
}person;

int main(int argc,char *argv[])
{
	FILE *fp,*fp1;

	person tony,tom;
	tony.age=100;
	strcpy(tony.name,"tony");
	strcpy(tony.email,"tony@qq.com");

	if((fp=fopen(argv[1],"wb"))==NULL){
		perror("create file error");
		exit(1);
	}

	if(fwrite(&tony,sizeof(person),1,fp)==-1){
		perror("wirte file error");
		exit(2);
	}
	fclose(fp);
	fp1 = fopen(argv[1],"rb");
	if(fp1!=NULL){
		if(fread(&tom,sizeof(person),1,fp1)>0){
			printf("%s %s %d\n",tom.name,tom.email,tom.age);	
		}	
	}else{
		printf("open file error");
	}
	fclose(fp1);
	return 0;
}


