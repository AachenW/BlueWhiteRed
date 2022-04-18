typedef struct Task {
    void (*function)(void *arg);
    void *arg;
}Task;

// 线程池结构体
struct ThreadPool {
    // 任务队列
    Task *taskQ;
    int queueCapacity;
    int queueSize;
    int queueFront;
    int queueRear;

    pthread_t managerID;
    pthread_t *threadIDs;
    int minNum;
    int maxNum;
    int busyNum;
    int liveNum;
    int exitNum;
    pthread_mutex_t mutexPool;
    pthread_mutex_t mutexBusy;
    pthread_cond_t notFull;
    pthread_cond_t notEmpty;

    int shutdown;
};