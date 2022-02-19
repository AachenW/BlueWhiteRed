#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <pthread.h>
#include <iostream>

pthread_mutex_t lock = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t print_cond = PTHREAD_COND_INITIALIZER;
int flag = 1;


void *print_a(void *arg) {
    for (int i = 0; i < 10; ++i) {
        pthread_mutex_lock(&lock);
        while (1 != flag) {
            pthread_cond_wait(&print_cond, &lock);
        }    
        std::cout << "A" << std::endl;
        flag = 2;
        pthread_mutex_unlock(&lock);
        pthread_cond_broadcast(&print_cond);
    }
}

void *print_b(void *arg) {
    for (int i = 0; i < 10; ++i) {
        pthread_mutex_lock(&lock);
        while (2 != flag) {
            pthread_cond_wait(&print_cond, &lock);
        }    
        std::cout << "B" << std::endl;
        flag = 3;
        pthread_mutex_unlock(&lock);
        pthread_cond_broadcast(&print_cond);
    }
    
}

void *print_c(void *arg) {
    for (int i = 0; i < 10; ++i) {
        pthread_mutex_lock(&lock);
        while (3 != flag) {
            pthread_cond_wait(&print_cond, &lock);
        }    
        std::cout << "C" << std::endl;
        flag = 1;
        pthread_mutex_unlock(&lock);
        pthread_cond_broadcast(&print_cond);
    }
    
}

int main(int argc, char **argv) {
    pthread_t tid_a, tid_b, tid_c;
    pthread_create(&tid_c, NULL, print_c, NULL);
    pthread_create(&tid_b, NULL, print_b, NULL);
    pthread_create(&tid_a, NULL, print_a, NULL);

    pthread_join(tid_a, NULL);
    pthread_join(tid_b, NULL);
    pthread_join(tid_c, NULL);
    
    return 0;
}