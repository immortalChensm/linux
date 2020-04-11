//
// Created by Administrator on 2020/4/11.
//

#ifndef PROCESSPOOL_H
#define PROCESSPOOL_H
#include <sys/ types .h>
#include <sys/ socket.h>
#include <netinet/ in.h>
#include <arpa/ inet.h>
#include <assert.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <fcntl .h>
#include <stdl ib.h>
#include <sys/epoll.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/stat.h>

/**
 * 工作原理说明
 * 并发模式：高效的半同步/半异步
 * 主进程和子进程：拥有共同的监听socket fd文件
 * 主进程和子进程：拥有各自的epoll内核事件表
 * 主进程和子进程：拥有各自的中断信号处理
 *
 * 主进程：
 * 1、创建一个双向流管道
 * 2、将双向流管道某一端加入到自己的epoll内核事件中【中断信号事件】
 * 3、sigaction安装自己的中断处理函数           【I/O事件】
 * 4、调用epoll_wait监听【监听socket,中断信号管道】2个文件描述符的就绪事件
 * 5、如果是中断信号就绪的事件，根据SIG类型判断【停止整个服务或是回收子进程的退出SIGCHILD并退出整个服务】
 * 6、如果是监听socket上的就绪事件产生，则通过轮询算法，找到某个子进程，同时向子进程的管道写入1数据，告诉子进程监听socket已经有客户端连接
 * 7、以上流程从4开始循环不止
 * PS:父进程收到SIGTEM,SIGINT中断信号时，向所有的子进程KILL杀掉，收到SIGCHLD信号时，关掉各个子进程的管道文件
 *
 * 子工作进程：
 * 1、创建一个双向流管道
 * 2、将双向流管道的某一端加入 到自己的epoll内核事件表中【中断信号事件】
 * 3、读取自己的进程管道文件，并加入到epoll内核事件表中
 * 4、调用epoll_wait等待就绪事件的发生
 * 5、就绪事件发生时，如果是自己的管道文件，则读取监听socket得到客户端连接，并将连接添加自己的监听epoll内核事件表中
 * 6、如果是中断信号事件发生时，自行处理一样的流程
 * 7、如果是连接socket上的事件发生时，则进行处理process
 * 8、以上从4开始循环不止
 * PS:子进程收到SIGINT,SIGTERM时直接停止服务，收到SIGCHILD时正常回收终止
 *
 * 他们的停止靠中断信号来完成
 *
 *
 */
class process{
public:
    process():m_pid(-1){}
public:
    pid_t m_pid;
    int m_pipefd[2];
};

template <typename T>
class processpool{
private:
    processpool(int listenfd,int process_number=8);
public:
    static processpool< T >*create(int listenfd,int process_number=8)
        {
            if(!m_instance){
                    m_instance = new processpool<T>(listenfd,process_number);
            }
            return m_instance;
        }
        ~processpool()
        {
            delete [] m_sub_process;
        }
        void run();
private:
    void setup_sig_pipe();
    void run_parent();
    void run_child();
private:
    static const int MAX_PROCESS_NUMBER =16;
    static const int USER_PER_PROCESS = 65536;
    static const int MAX_EVENT_NUMBER = 10000;
    int m_process_number;
    int m_idx;
    int m_epollfd;
    int m_listenfd;
    int m_stop;
    process *m_sub_process;
    static processoll< T > *processpool< T >::m_instance = NULL;
    static int sig_pipefd[2];
    static int setnonblocking(int fd)
        {
            int old_option = fcntl(fd,F_GETFL);
            int new_option = old_option | O_NONBLOCK;
            fcntl(fd,F_SETFL,new_option);
            return old_option;
        }
    static void addfd(int epollfd,int fd)
        {
            struct epoll_event event;
            event.data.fd = fd;
            event.events = EPOLLIN | EPOLLET;
            epoll_ctl(epollfd,EPOLL_CTL_ADD,fd,&event);
            setnonblocking(fd);
        }
        static void removefd(int epollfd,int fd)
        {
            epoll_ctl(epollfd,EPOLL_CTL_DEL,fd,0);
            close(fd);
        }
        static void sig_handler(int sig)
        {
            int save_errno = errno;
            int msg = sig;
            send(sig_pipefd[1],(char*)&msg,1,0);
            errno = save_errno;
        }
        static void addsig(int sig,void (handler)(int),bool restart=true)
        {
            struct sigaction sa;
            memset(&sa,'\0',sizeof(sa));
            sa.sa_handler = handler;
            if(restart){
                    sa.sa_flags | = SA_RESTART;
            }
            sigfillset(&sa.sa_mask);
            assert(sigaction(sig,&sa,NULL)!=-1);
        }
        template< typename T >
        processpool< T >::processpool(int listenfd,int process_number):m_listenfd(listenfd),m_process_number(process_number),m_idx(-1),m_stop(false)
        {
            assert((process_number>0)&&(process_number<=MAX_PROCESS_NUMBER));
            m_sub_process = new process[process_number];
            assert(m_sub_process);

            //创建多进程 每个进程都有一个管道文件
            for(int i=0;i<process_number;i++){
                    //每个进程一个管道文件
                    int ret = socketpair(PF_UNIX,SOCK_STREAM,0,m_sub_process[i].m_pipefd);
                    assert(ret==0);
                    //主进程存储各个子进程的进程号
                    m_sub_process[i].m_pid = fork();

                    assert(m_sub_process[i].m_pid>=0);
                    if(m_sub_process[i].m_pid>0){
                            close(m_sub_process[i].m_pipefd[1]);
                            continue;
                    }else{
                            close(m_sub_process[i].m_pipefd[0]);
                            m_idx=i;
                            break;
                    }
            }
        }
        template < typename T >
        void processpool< T >::setup_sig_pipe()
        {
            m_epollfd = epoll_create(5);
            assert(m_epollfd!=-1);
            int ret = socketpair(PF_UNIX,SOCK_STREAM,0,sig_pipefd);
            assert(ret!=-1);

            setnonblocking(sig_pipefd[1]);
            addfd(m_epollfd,sig_pipefd[0]);
            addsig(SIGCHLD,sig_handler);
            addsig(SIGTERM,sig_handler);
            addsig(SIGINT,sig_handler);
            addsig(SIGPIPE,SIG_IGN);
        }
        template < typename T >
        void processpool < T >::run()
        {
            if(m_idx!=-1){
                    run_child();
                    return ;
            }
            run_parent();
        }
        template < typename T >
        void processpool< T >::run_child()
        {
                //安装各自的信号处理器
                //创建各自的epollfd
                //创建各自的sig_pipefd socketpair双向流管道同时读端加入到epoll内核事件监听表中
            setup_sig_pipe();

            int pipefd = m_sub_process[m_idx].m_pipefd[1];
            //将当前进程的管道加入到epoll内核事件中表
            addfd(m_epollfd,pipefd);
            struct epoll_event events[MAX_EVENT_NUMBER];
            T* users = new T [ USER_PER_PROCESS ];
            assert(users);
            int number = 0;
            int ret = -1;
            while(!m_stop){
                    //子进程收到进程写管道的事件时会发生就绪文件
                    number = epoll_wait(m_epollfd,events,MAX_EVENT_NUMBER,-1);
                    if((number<0)&&(errno!=EINTR)){
                            printf("epoll failure\n");
                            break;
                    }
                    for(int i=0;i<number;i++){
                            int sockfd = events[i].data.fd;

                            //产生的就绪事件文件是当前进程的就绪文件【管道】表示父进程的监听socket接收到连接并向子进程的管道发送时运行下面逻辑
                            if((sockfd == pipefd)&&(events[i].events&EPOLLIN)){
                                    int client = 0;
                                    ret = recv(sockfd,(char*)&client,sizeof(client),0);
                                    if(((ret<0)&&(errno!=EAGIN))||ret==0){
                                            continue;
                                    }else{
                                            //读取监听socket上的连接socket
                                            struct sockaddr_in client_address;
                                            socklen_t client_addrlength = sizeof(client_address);
                                            int connfd = accept(m_listenfd,(struct sockaddr*)&client_address,&client_addrlength);
                                            if(connfd<0){
                                                    printf("error is :%d\n",errno);
                                                    continue;
                                            }
                                            //子进程维护自己的连接socket
                                            addfd(m_epollfd,connfd);
                                            users[connfd].init(m_epollfd,connfd,client_address);
                                    }
                            }
                            //信号事件逻辑
                            else if((sockfd ==sig_pipefd[0])&&(events[i].events&EPOLLIN)){
                                    int sig;
                                    char signals[1024];
                                    ret = recv(sig_pipefd[0],signals,sizeof(signals),0);
                                    if(ret<=0){
                                            continue;
                                    }
                                    else{
                                            for(int i=0;i<ret;i++){
                                                    switch (signals[i]){
                                                        case SIGCHLD:
                                                        {
                                                                pid_t pid;
                                                                int stat;
                                                                while((pid=waitpid(-1,&stat,WNOHANG))>0){
                                                                        continue;
                                                                }
                                                                break;
                                                        }
                                                        case SIGTERM:
                                                        case SIGINT:
                                                        {
                                                                m_stop = true;
                                                                break;
                                                        }
                                                            default:
                                                            {
                                                                    break;
                                                            }
                                                    }
                                            }
                                    }
                            }
                            //子进程上的连接socket事件处理逻辑
                            else if(events[i].events & EPOLLIN){
                                    users[sockfd].process();
                            }else{
                                    continue;
                            }
                    }
            }
            delete [] users;
            users = NULL;
            close(pipefd);
            close(m_epollfd);
        }
        template < typename T >
        void processpool< T >::run_parent()
        {
            //安装各自的信号处理器
            //创建各自的epollfd
            //创建各自的sig_pipefd socketpair双向流管道同时读端加入到epoll内核事件监听表中
            setup_sig_pipe();
            //将监听socket添加到epoll内核事件表中并监听
            addfd(m_epollfd,m_listenfd);
            struct epoll_event events[MAX_EVENT_NUMBER];
            int sub_process_counter = 0;
            int new_conn = 1;
            int number = 0;
            int ret = -1;
            while(!m_stop){
                    //监控 监听socket上的读就绪事件
                    number = epoll_wait(m_epollfd,events,MAX_EVENT_NUMBER,-1);
                    if((number<0)&&(errno!=EINTR)){
                            printf("epoll failure\n");
                            break;
                    }
                    for(int i=0;i<number;i++){
                            int sockfd = events[i].data.fd;
                            //父进程只管监听socket上的读就绪事件
                            //有连接连接时，通过某种算法【轮询】向工作子进程通过管道发送通知
                            //监听socket套接字父进程和各个子进程都有【共享同一个监听套接字】
                            if(sockfd==m_listenfd){

                                    //轮询算法查找某一个子进程
                                    int i = sub_process_counter;
                                    do{
                                            if(m_sub_process[i].m_pid!=-1){
                                                    break;
                                            }
                                            i = (i+1)%m_process_number;
                                    }
                                    while(i!=sub_process_counter);
                                    if(m_sub_process[i].m_pid==-1){
                                            m_stop = true;
                                            break;
                                    }
                                    sub_process_counter = (i+1)%m_process_number;
                                    //向某个子进程的管道发送监听socket上的读就绪事件
                                    send(m_sub_process[i].m_pipefd[0],(char*)&new_conn,sizeof(new_conn),0);
                                    printf("send request to child %d\n",i);
                            }
                            else if((sockfd == sig_pipefd[0])&&(events[i].events& EPOLLIN)){
                                    int sig;

                                    //父进程的读管道事件发生时
                                    char signals[1024];
                                    ret = recv(sig_pipefd[0],signals,sizeof(signals),0);
                                    if(ret<=0){
                                            continue;
                                    }else{

                                            for(int i=0;i<ret;i++){
                                                    switch (signals[i]){
                                                        case SIGCHLD:
                                                        {
                                                                pid_t pid;
                                                                int stat;
                                                                while((pid=waitpid(-1,&stat,WNOHANG))>0){
                                                                        for(int i=0;i<m_process_number;i++){
                                                                                if(m_sub_process[i].m_pid==pid){
                                                                                        printf("child %d join\n");
                                                                                        close(m_sub_process[i].m_pipefd[0]);
                                                                                        m_sub_process[i].m_pid = -1;
                                                                                }
                                                                        }
                                                                }
                                                                m_stop = true;
                                                                for(int i=0;i<m_process_number;i++){
                                                                        if(m_sub_process[i].m_pid!=-1){
                                                                                m_stop = false;
                                                                        }
                                                                }
                                                                break;
                                                        }
                                                        case SIGTERM:
                                                        case SIGINT:
                                                        {
                                                                printf("kill all the child now\n");
                                                                for(int i=0;i<m_process_number;i++){
                                                                        int pid = m_sub_process[i].m_pid;
                                                                        if(pid!=-1){
                                                                                kill(pid,SIGTERM);
                                                                        }
                                                                }
                                                                break;
                                                        }
                                                            default:
                                                            {
                                                                    break;
                                                            }
                                                    }
                                            }
                                    }
                            }
                            else{
                                    continue;
                            }
                    }
            }
            close(m_epollfd);
        }
};

