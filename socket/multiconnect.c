#include <stdio.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <fcntl.h>
#include <unistd.h>
#include <pthread.h>
#include <assert.h>
void *connect_server(void *);
int main(int argc,char *argv[])
{
	int port = atoi(argv[2]);
	const char *ip = argv[1];
	int conn_num = atoi(argv[3]);
	struct sockaddr_in address;
	bzero(&address,sizeof(address));

	address.sin_family = AF_INET;
	address.sin_port = htons(port);
	address.sin_addr.s_addr = inet_addr(ip);
//	int j=0;
//	int sockfd[conn_num];
//	for(;j<conn_num;j++){
//		sockfd[j] = socket(PF_INET,SOCK_STREAM,0);	
//		assert(sockfd[j]!=-1);
//	}

	//int conn_num = atoi(argv[3]);
	struct connect_data{
		int sockfd;
		struct sockaddr_in addr;
	};

	int i=0;pthread_t tid[conn_num];
	for(;i<conn_num;i++){
		struct connect_data server;
	//	server.sockfd = socket(PF_INET,SOCK_STREAM,0);
	//	server.addr = address;
	//	printf("i=%d,sockfd=%d\n",i,server.sockfd);
		pthread_create(&tid[i],NULL,connect_server,(void*)&address);
		//pthread_join(tid[i],NULL);
	}
	for(i=0;i<conn_num;i++){
		pthread_join(tid[i],NULL);
	}

	sleep(2);
	printf("over run\n");

	return 0;
}
void *connect_server(void *arg)
{
//	struct connect_data {
//		int sockfd;
//		struct sockaddr_in addr;
//	};
//	struct connect_data server;
	struct sockaddr_in server  = *(struct sockaddr_in*)arg;
//	struct sockaddr_in client;
//	socklen_t client_len = sizeof(client);
//	printf("sockfd=%d\n",server.sockfd);
//	while(1){
//		printf("tid=%d run\n",pthread_self());
//		sleep(2);
//	}
//	return ;
	printf("hi %d\n",pthread_self());
	int sockfd = socket(PF_INET,SOCK_STREAM,0);
	int conn_ret = connect(sockfd,(struct sockaddr*)&server,sizeof(server));
	if(conn_ret!=-1){
		char *temp[]={"A","B","C"};
		while(1){
			send(sockfd,temp,1,0);
			printf("tid =%d send data %s\r\n",pthread_self(),temp[0]);
			sleep(3);
		}
	}else{
		printf("tid=%d connect failure %s\n",pthread_self(),strerror(errno));
	}
	return (void*)0;
	
}
