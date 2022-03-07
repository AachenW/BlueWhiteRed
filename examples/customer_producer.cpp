#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>

#define MAX 100

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
sem_t full;
sem_t empty;

int top = 0;
int bottom = 0;

// 第一种实现信号量配合互斥锁实现
void* producer(void *arg) {
    for (int i = 0; i < MAX * 2; ++i) {
        printf("producer is preparing data\n");
        sem_wait(&empty);   // 若空槽个数低于0阻塞

        pthread_mutex_lock(&mutex);

        top = (top + 1) % MAX;
        printf("now top is %d\n", top);

        pthread_mutex_unlock(&mutex);

        sem_post(&full);    // 若空槽满了则阻塞
    }

    return (void*)1;
}

void* consume(void *arg) {
    for (int i = 0; i < MAX * 2; ++i) {
        printf("consumer is consuming data\n");
        sem_wait(&full);    //若填充个数低于0阻塞

        pthread_mutex_lock(&mutex);

        bottom = (bottom + 1) % MAX;
        printf("now bottom is %d\n", bottom);

        pthread_mutex_unlock(&mutex);
        sem_post(&empty);
    }

    return (void*)2;
}



// 第二种是条件变量配合互斥锁实现
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t notfull = PTHREAD_COND_INITIALIZER;      //是否队满
pthread_cond_t notempty = PTHREAD_COND_INITIALIZER;     //是否队空

int top = 0;
int bottom = 0;

void* producer(void *arg) {
    for (int i = 0; i < MAX * 2; ++i) {
        pthread_mutex_lock(&mutex);
        while ((top + 1) % MAX == bottom) {
            printf("full! producer is waiting\n");
            pthread_cond_wait(&nofull, &mutex);
        }
        
        top = (top + 1) % MAX;
        printf("now top is %d\n", top);
        pthread_cond_signal(&notempty);
        pthread_mutex_unlock(&mutex);
    }
    return (void*)1;
}

void* consume(void *arg) {
    for (int i = 0; i < MAX * 2; ++i) {
        pthread_mutex_lock(&mutex);
        while (top % MAX = bottom) {
            printf("empty! consumer is waiting\n");
            pthread_cond_wait(&noempty, &mutex);
        }
        bottom = (bottom + 1) % MAX;
        printf("now bottom is %d\n", bottom);
        pthread_mutex_unlock(&mutex);
        pthread_cond_signal(&nofull);
    }

    return (void*)2;
}
int main(int argc, char **argv) {
    pthread_t tid1;
    pthread_t tid2;
    pthread_t tid3;
    pthread_t tid4;

    int ret1;
    int ret2;
    int ret3;
    int ret4;

    sem_init(&full, 0, 0);
    sem_init(&empty, 0, MAX);

    pthread_create(&tid1, NULL, producer, NULL);
    pthread_create(&tid2, NULL, consume, NULL);
    pthread_create(&tid3, NULL, producer, NULL);
    pthread_create(&tid4, NULL, consume, NULL);

    pthread_join(tid1, (void**)&ret1);
    pthread_join(tid2, (void**)&ret2);
    pthread_join(tid3, (void**)&ret3);
    pthread_join(tid4, (void**)&ret4);
    
    return 0;
}