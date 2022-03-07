#include <pthread.h>
#include <sys/sem>

#define N 5;
semaphore fork[5];

void philosopher_eating(int i) {
    while (true) {
        think();

        if (i % 2) {
            P(fork[i]);
            P(fork[(i + 1) % N]);
        } else {
            P(fork[(i + 1) % N]);
            P(fork[i]);
        }

        eat();

        V(fork[i]);
        V(fork[(i + 1) % N]);
    }
}