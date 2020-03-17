#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <assert.h>
#include <string.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <sys/select.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <poll.h>

#define FDMAXNUM 100
//#define _GNU_SOURCE

void Init_Fds(struct pollfd *fds)
{
	int i=0;

	for(;i<FDMAXNUM;i++){
		fds[i].fd = -1;
		fds[i].events = 0;
		fds[i].revents = 0;
	}
}

void DeleteFd(int fd,struct pollfd *fds)
{
	int i=0;

	for(;i<FDMAXNUM;i++){
		if(fds[i].fd == fd){
			fds[i].fd = -1;
			fds[i].events = 0;

			break;
		}
	}
}

void AddFds(int fd,struct pollfd *fds)
{
	int i=0;

	for(;i<FDMAXNUM;i++){
		if(fds[i].fd == -1){
			fds[i].fd = fd;	
			fds[i].events = POLLIN | POLLRDHUP;
			break;
		}
	}
}

void GetClientLink(int fd,struct pollfd *fds,struct sockaddr_in cli)
{
	int len = sizeof(cli);
	int c = accept(fd,(struct sockaddr*)&cli,&len);

	AddFds(c,fds);
}

void DealClientData(int fd,struct pollfd *fds,int rdhup)
{
	if(rdhup){
		DeleteFd(fd,fds);
		close(fd);
		return ;
	}

	char buff[128] = {0};

	int n = recv(fd,buff,127,0);
	if(n<=0){
		DeleteFd(fd,fds);
		close(fd);
		return ;
	}

	printf("%s\n",buff);
	send(fd,"OK",2,0);
}
int main(int argc,char *argv[])
{
	int sockfd = socket(AF_INET,SOCK_STREAM,0);

	assert(sockfd!=-1);

	struct sockaddr_in server,client;

	bzero(&server,sizeof(server));
	server.sin_family = AF_INET;	
	server.sin_port = htons(12345);
	server.sin_addr.s_addr = inet_addr("0.0.0.0");

	int res = bind(sockfd,(struct sockaddr*)&server,sizeof(server));

	assert(res!=-1);

	listen(sockfd,5);

	struct pollfd fds[FDMAXNUM];

	Init_Fds(fds);

	fds[0].fd = sockfd;
	fds[0].events = POLLIN;

	while(1){
		int n = poll(fds,FDMAXNUM,-1);

		if(n<=0){
			exit(0);
		}

		int i=0;

		for(;i<FDMAXNUM;i++){
			if(fds[i].fd == -1){
				continue;
			}

			if(fds[i].revents & POLLIN){
				if(fds[i].fd == sockfd){
					GetClientLink(fds[i].fd,fds,client);
				}

				else if(fds[i].revents &POLLRDHUP){
					DealClientData(fds[i].fd,fds,1);
				}else{
					DealClientData(fds[i].fd,fds,0);
				}
			}
		}
	}

	return 0;
}
