#include <pthread.h>
#include <sys/sem>

#define N 5;
sem fork[5];

void philosopher_eating(int i) {
    while (true) {
        think();

        if (i % 2) {
            sem_wait(fork[i]);
            sem_wait(fork[(i + 1) % N]);
        } else {
            sem_wait(fork[(i + 1) % N]);
            sem_wait(fork[i]);
        }

        eat();

        sem_post(fork[i]);
        sem_post(fork[(i + 1) % N]);
    }
}