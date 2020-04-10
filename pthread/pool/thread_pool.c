//
// Created by 1655664358@qq.com on 2020/4/10.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>
#include <time.h>
#include <assert.h>
#include <errno.h>
#include <unistd.h>
typedef struct task
{
    void *(*pfun)(void*);
    void *arg;
    struct task *_next;
}task_t;
typedef struct condition
{
    pthread_mutex_t pmutex;
    pthread_cond_t pcond;
}condition_t;
typedef struct threadpool
{
    condition_t cond;
    task_t *first;
    task_t *tail;
    int max_thread;
    int idle;
    int counter;
    int quit;
}threadpool_t;
void *run(void *arg)
{

    int id = *(int *)arg;
    free(arg);
    printf("%#lX thread running!id=%d\n",pthread_self(),id);
    sleep(1);
}
int condition_init(condition_t *cond)
{
    return pthread_cond_init(&cond->pcond,NULL)||pthread_mutex_init(&cond->pmutex,NULL);
}
int condition_lock(condition_t *cond)
{
    return pthread_mutex_lock(&cond->pmutex);
}
int condition_unlock(condition_t *cond)
{
    return pthread_mutex_unlock(&cond->pmutex);
}
int condition_wait(condition_t *cond)
{
    return pthread_cond_wait(&cond->pcond,&cond->pmutex);
}
int condition_timewait(condition_t *cond,const struct timespec *abstime)
{
    return pthread_cond_timedwait(&cond->pcond,&cond->pmutex,abstime);
}
int condition_signal(condition_t *cond)
{
    return pthread_cond_signal(&cond->pcond);
}
int condition_broadcast(condition_t *cond)
{
    return pthread_cond_broadcast(&cond->pcond);
}
int condition_destroy(condition_t *cond)
{
    return pthread_mutex_destroy(&cond->pmutex)&&pthread_cond_destroy(&cond->pcond);
}
void threadpool_init(threadpool_t *pool,int max)
{
    assert(NULL!=pool);
    condition_init(&pool->cond);
    pool->first = NULL;
    pool->tail = NULL;
    pool->max_thread = max;
    pool->idle = 0;
    pool->counter = 0;
    pool->quit = 0;
}
void *thread_fun(void *arg)
{
    threadpool_t *pool = (threadpool_t*)arg;
    int timeout = 0;
    while (1){
        condition_lock(&pool->cond);
        pool->idle++;
        timeout = 0;
        while (pool->first==NULL&&pool->quit==0){
            struct timespec ts;
            clock_gettime(CLOCK_REALTIME,&ts);
            ts.tv_sec+=2;
            int r = condition_timewait(&pool->cond,&ts);
            if(r == ETIMEDOUT){
                timeout = 1;
                break;
            }
        }
        pool->idle--;
        if (NULL!=pool->first){

            task_t *p_first = pool->first;
            pool->first = p_first->_next;
            condition_unlock(&pool->cond);
            (p_first->pfun)(p_first->arg);
            condition_lock(&pool->cond);
            free(p_first);
            p_first = NULL;
        }
        if (NULL==pool->first&&1==timeout){
            condition_unlock(&pool->cond);
            printf("%#lx thread TIMEOUT! QUIT!!!\n",pthread_self());
            break;
        }
        if (pool->quit==1&&NULL==pool->first){
            printf("%#lx thread destroy!\n",pthread_self());
            pool->counter--;
            if (0==pool->counter){
                condition_signal(&pool->cond);
            }
            condition_unlock(&pool->cond);
            break;
        }
        condition_unlock(&pool->cond);
    }
}
void threadpool_destroy(threadpool_t *pool)
{
    if (pool->quit)return;
    condition_lock(&pool->cond);
    pool->quit=1;
    if (pool->counter>0){
        if (pool->idle>0)
            condition_broadcast(&pool->cond);
    }
    while (pool->counter>0){
        condition_wait(&pool->cond);
    }
    condition_unlock(&pool->cond);
    condition_destroy(&pool->cond);
}
void threadpool_add(threadpool_t *pool,void *(*pf)(void*),void *arg)
{
    task_t *new_task = (task_t*)malloc(sizeof(task_t));
    new_task->pfun = pf;
    new_task->arg = arg;
    new_task->_next = NULL;

    condition_lock(&pool->cond);

    if (NULL == pool->first){
        pool->first = new_task;
    }else{
        pool->tail->_next = new_task;
    }
    pool->tail = new_task;
    if(pool->idle>0){
        condition_signal(&pool->cond);
    }
    else if (pool->counter<pool->max_thread){
        pthread_t tid;
        pthread_create(&tid,NULL,thread_fun,(void*)pool);
        pool->counter++;
    }
    condition_unlock(&pool->cond);
}
int main()
{
    threadpool_t pool;
    threadpool_init(&pool,3);
    int i=0;
    for (;i<10;i++) {
        int *p = (int*)malloc(sizeof(int));
        *p = i;
        threadpool_add(&pool,run,(void*)p);
    }
    threadpool_destroy(&pool);
    sleep(15);
    return 0;
}
