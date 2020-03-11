#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/time.h>
#include <sys/socket.h>
#include <sys/select.h>

#define BUF_SIZE 100
void error_handing(char *buf);
int main(int argc,char *argv[])
{
	int serv_sock,clnt_sock;

	struct sockaddr_in serv_adr,clnt_adr;

	struct timeval timeout;

	fd_set reads,cpy_reads,writes,cpy_writes;

	socklen_t adr_sz;

	int fd_max,str_len,fd_num,i;

	char buf[BUF_SIZE];

	if(argc!=2){
		printf("useage:%s <port>\n",argv[0]);
		exit(1);
	}

	serv_sock = socket(PF_INET,SOCK_STREAM,0);

	memset(&serv_adr,0,sizeof(serv_adr));

	serv_adr.sin_family = AF_INET;
	serv_adr.sin_addr.s_addr = htonl(INADDR_ANY);

	serv_adr.sin_port = htons(atoi(argv[1]));

	if(bind(serv_sock,(struct sockaddr*)&serv_adr,sizeof(serv_adr))==-1){
		error_handing("bind() error");
	}
	if(listen(serv_sock,5)==-1){
		error_handing("listen() error");
	}

	FD_ZERO(&reads);
	FD_ZERO(&writes);
	FD_SET(serv_sock,&reads);


	fd_max = serv_sock;

	while(1){
		cpy_reads = reads;
		cpy_writes = writes;
		//printf("init=%#X\n",cpy_reads);
		timeout.tv_sec = 5;
		timeout.tv_usec = 5000;

		if((fd_num = select(fd_max+1,&cpy_reads,&cpy_writes,0,&timeout))==-1){
			perror("select error");break;
		}

		if(fd_max == 0){
			continue;
		}
		//printf("select=%#X\n",cpy_reads);

		for(i=0;i<fd_max+1;i++){
			
			printf("fd=%d,cpy_reads=%d,cpy_reads=%#x,reads=%d,reads=%#x,writes=%d,cpy_writes=%d\n",i,cpy_reads,cpy_reads,reads,reads,writes,cpy_writes);
			if(FD_ISSET(i,&cpy_reads)){
						
				if(i == serv_sock){
					adr_sz = sizeof(clnt_adr);
					clnt_sock = accept(serv_sock,(struct sockaddr*)&clnt_adr,&adr_sz);
					FD_SET(clnt_sock,&reads);
					FD_SET(clnt_sock,&writes);

					if(fd_max<clnt_sock){
						fd_max = clnt_sock;
					}

					printf("connected client:%d\n",clnt_sock);
				}
				else{
					
					str_len = read(i,buf,BUF_SIZE);

					if(str_len == 0){
						FD_CLR(i,&reads);
						FD_CLR(i,&writes);
						close(i);
						printf("closed client:%d\n",i);
					}else{
						write(i,buf,str_len);
					}
				}
			}
			if(FD_ISSET(i,&cpy_writes)){
				send(i,"server",6,0);
			}
		}
	}

	close(serv_sock);
}

void error_handing(char *buf)
{
	fputs(buf,stderr);
	fputc('\n',stderr);
	exit(1);
}
