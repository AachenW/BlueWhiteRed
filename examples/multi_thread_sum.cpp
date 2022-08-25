#include <pthread.h>
#include <unistd.h>
#include <bits/stdc++.h>

void *func(void *arg) {
    long i = (long)arg;
    int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum5 = 0;
    int sum6 = 0, sum7 = 0, sum8 = 0, sum9 = 0, sum10 = 0;

    int sum = 0, a = 0;

    switch(i) {
        case 0:
        {
            for (a = 1; a < 1000; ++a) {
                sum1 += a;
            }
            return (void*)sum1;
            break;
        }
        case 1:
        {
            for (a = 1000; a < 2000; ++a) {
                sum2 += a;
            }
            return (void*)sum2;
            break;
        }
        case 2:
        {
            for (a = 2000; a < 3000; ++a) {
                sum3 += a;
            }
            return (void*)sum3;
            break;
        }
        case 3:
        {
            for (a = 3000; a < 4000; ++a) {
                sum4 += a;
            }
            return (void*)sum4;
            break;
        }
        case 4:
        {
            for (a = 4000; a <= 5000; ++a) {
                sum5 += a;
            }
            return (void*)sum5;
            break;
        }
        default:
            break;
    }

    return nullptr;
}

int main(int argc, char **argv) {
    pthread_t tid[5];
    int ret, i, error;
    long sum = 0;
    void* c[5];

    for (i = 0; i < 5; ++i) {
        ret = pthread_create(tid + i, NULL, func, (void*)i);
        if (0 != ret) {
            fprintf(stderr, "pthread can't create no%s", strerror(ret));
            exit(1);
        }
    }


    for (i = 0; i < 5; ++i) {
        error = pthread_join(tid[i], c + i);
        sum += (long)c[i];
    }

    printf("sum = sum1 + sum2 + sum3 + sum4 + sum5 = %ld\n", sum);

    sleep(i);

    return 0;
}
