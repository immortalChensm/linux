#include <arpa/inet.h>
#include <assert.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/epoll.h>
#include <pthread.h>

#define MAX_EVENT_NUMBER 1024
#define BUFFER_SIZE 1024

struct fds
{
	int epollfd;
	int sockfd;
};

int setnonblocking(int fd)
{
	int old_option = fcntl(fd,F_GETFL);
	int new_option = old_option|O_NONBLOCK;
	fcntl(fd,F_SETFL,new_option);
	return old_option;
}

void addfd(int epollfd,int fd,int oneshot)
{
	struct epoll_event event;
	event.data.fd = fd;
	event.events = EPOLLIN|EPOLLET;
	if(oneshot){
		event.events |=EPOLLONESHOT;
	}
	epoll_ctl(epollfd,EPOLL_CTL_ADD,fd,&event);
	setnonblocking(fd);
}

void reset_oneshot(int epollfd,int fd)
{
	struct epoll_event event;
	event.data.fd = fd;
	event.events = EPOLLIN|EPOLLET|EPOLLONESHOT;
	epoll_ctl(epollfd,EPOLL_CTL_ADD,fd,&event);
	
}


void *worker(void *arg)
{
	int sockfd = ((struct fds*)arg)->sockfd;
	int epollfd = ((struct fds*)arg)->epollfd;

	printf("new thread to receive data on fd:%d\n",sockfd);

	char buf[BUFFER_SIZE];
	memset(buf,'\0',BUFFER_SIZE);
		
	while(1){
		
		int ret = recv(sockfd,buf,BUFFER_SIZE-1,0);
		if(ret==0){
			close(sockfd);
			printf("foreiner closed the connection\n");
			break;
		}
		else if(ret<0){
			if(errno== EAGAIN){
				reset_oneshot(epollfd,sockfd);
				printf("read later\n");
				break;
			}
		}
		else{
			printf("get content:%s\n",buf);
			sleep(3);
		}
		printf("end thread receiving data on fd:%d\n",sockfd);
	}
}

int main(int argc,char *argv[])
{
	if(argc<=2){
		printf("useage:%s ip_address port_number\n",basename(argv[0]));
		return 1;
	}

	const char *ip = argv[1];
	int port = atoi(argv[2]);

	int ret = 0,i=0;
	
	/*************************************************************/
	printf("EPOLLIN=%d,EPOLLOUT=%d,EPOLLET=%d,EPOLLONESHOT=%d,EPOLLIN|EPOLLET=%d,EPOLLIN&EPOLLONESHOT=%d",EPOLLIN,EPOLLOUT,EPOLLET,EPOLLONESHOT,EPOLLIN|EPOLLET,EPOLLIN&EPOLLONESHOT);


	struct sockaddr_in address;
	bzero(&address,sizeof(address));
	address.sin_family = AF_INET;
	inet_pton(AF_INET,ip,&address.sin_addr);
	address.sin_port = htons(port);

	int listenfd = socket(PF_INET,SOCK_STREAM,0);

	assert(listenfd>=0);

	ret = bind(listenfd,(struct sockaddr*)&address,sizeof(address));
	assert(ret!=-1);

	ret = listen(listenfd,5);
	assert(ret!=-1);

	struct epoll_event events[MAX_EVENT_NUMBER];
	int epollfd = epoll_create(5);

	assert(epollfd!=-1);

	addfd(epollfd,listenfd,0);

	while(1){
		
		int ret = epoll_wait(epollfd,events,MAX_EVENT_NUMBER,-1);
		
		if(ret<0){
			printf("epoll failure\n");
		}

		for(i=0;i<ret;i++){
			int sockfd = events[i].data.fd;
			if(sockfd == listenfd){
				
				struct sockaddr_in client;
				socklen_t client_len = sizeof(client);
				int connfd = accept(listenfd,(struct sockaddr*)&client,&client_len);
				addfd(epollfd,connfd,1);
			}
			else if(events[i].events & EPOLLIN){
				pthread_t thread;
				struct fds fds_fork_new_worker;
				fds_fork_new_worker.epollfd = epollfd;
				fds_fork_new_worker.sockfd = sockfd;

				pthread_create(&thread,NULL,worker,(void*)&fds_fork_new_worker);
			}
			else{
				printf("something else \n");
			}
		}
	}
	close(listenfd);
	return 0;
}
