#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <assert.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#define BUF_SIZE 1024

int main(int argc,char *argv[])
{
	if(argc<=2){
		printf("usage:%s ip_address port_number\n",basename(argv[0]));
		return 1;
	}

	printf("master pid %d\n",getpid());


	const char *ip = argv[1];
	int port = atoi(argv[2]);

	struct sockaddr_in address;

	bzero(&address,sizeof(address));

	address.sin_family = AF_INET;

	inet_pton(AF_INET,ip,&address.sin_addr);

	address.sin_port = htons(port);

	int sock = socket(PF_INET,SOCK_STREAM,0);

	assert(sock>=0);

	int ret = bind(sock,(struct sockaddr*)&address,sizeof(address));
	assert(ret!=-1);

	ret = listen(sock,5);

	assert(ret!=-1);

	struct sockaddr_in client;
	socklen_t client_addrlength = sizeof(client);
	int connfd = accept(sock,(struct sockaddr*)&client,&client_addrlength);
	printf("accept a connfd file %d\n",connfd);
	
	//char *command = "ls -al /proc/%d/fd";
	char command[100] = {0};
	sprintf(command,"ls -al /proc/%d/fd",getpid());
	system(command);
	if(connfd <0){
		printf("errno is:%d\n",errno);
	}else{
		char buffer[BUF_SIZE];

		memset(buffer,'\0',BUF_SIZE);

		//ret = recv(connfd,buffer,BUF_SIZE-1,0);
		ret = recvfrom(connfd,buffer,BUF_SIZE,0,NULL,NULL);

		printf("1 got %d bytes of normal data %s\n",ret,buffer);

		//memset(buffer,'\0',BUF_SIZE);
		//ret = recv(connfd,buffer,BUF_SIZE-1,MSG_OOB);
		//printf("got %d bytes of oob data %s\n",ret,buffer);

		memset(buffer,'\0',BUF_SIZE);
		ret = recv(connfd,buffer,BUF_SIZE-1,0);

		printf("2 got %d bytes of normal_data %s\n",ret,buffer);
		
		//send(connfd,buffer,ret,0);
		sendto(connfd,buffer,strlen(buffer),0,NULL,0);
		close(connfd);
	}

	close(sock);

	return 0;
}
