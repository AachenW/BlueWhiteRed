typedef int semaphore;
int read_count;
semaphore x = 1,        // x用于确保read_count被正确更新 
semaphore wsem = 1;      // wsem实施互斥


// 读者优先
void reader() {
    while (true) {
        semWait(x);
        ++read_count;
        if (1 == read_count) {
            semWait(wsem);
        }
        semSignal(x);
        READUNIT();
        semWait(x);
        --read_count;
        if (0 == read_count) {
            semSignal(wsem);
        }
        semSignal(x);
    }
}

void writer() {
    while (true) {
        semWait(wsem);
        WRITEUINT();
        semSignal(wsem);
    }
}

// 写者优先
int read_count, writer_count;
semaphore rCountMutex = 1;      // 控制对rCount的互斥修改，初始值为1
semaphore wCountMutex = 1;      // 控制writer_counter的更新， 初始值为1
semaphore z = 1;
semaphore wDataMutex = 1;       // 控制写者写操作的互斥信号量，初始值为1
semaphore rMutex = 1;           // 至少由一个写进程准备访问数据区时，用于禁止所有的读进程


void reader() {
    while (true) {
        semWait(z); // 在rMutex上不允许建造长队列，否则写进程将无法跳过这个队列，因此只允许一个读进程在rMutex上排队，而所有其他进程在等待rMutex前，在信号量z上排队
            semWait(rMutex);                
                semWait(rCountMutex);       // 进入临界区
                ++read_count;
                if (1 == read_count) {
                    semWait(wDataMutex);    // 当第一个读者进入，如果有写着则阻塞写着写操作
                }
                semSignal(rCountMutex);     // 离开临界区
            semSignal(rMutex);              
        semSignal(z);

        READUNIT();

        semWait(rCountMutex);
            --read_count;
            if (0 == read_count) {
                semSignal(wDataMutex);      // 当没有读者了，则唤醒阻塞中写者的写操作
            }
        semSignal(rCountMutex);
    }
    
}

void writer() {
    while (true) {
        semWait(wCountMutex);               // 进入临界区
            ++writer_count;
            if (1 == writer_count) {
                semWait(rMutex);            // 当第一个写者进入，如果有读者则阻塞读者
            }
        semSignal(wCountMutex);

        semWait(wDataMutex);
        WRITEUNIT();
        semSignal(wDataMutex);

        semWait(wCountMutex);
            --writer_count;
            if (0 == writer_count) {
                semSignal(rMutex);            // 最后一个写者离开了，则唤醒读者
            }
        semSignal(wCountMutex);
    }
}

/*
**  方案三：公平策略
**  1. 优先级相同；
**  2. 读者、写者互斥访问
**  3. 只能一个写者访问临界区
**  4. 可以有多个读者同时访问临界资源
*/

semaphore rCountMutex;  // 控制对rCount的互斥修改，初始值为1
semaphore wDataMutex;
semaphore flag;
int rCount = 0;

void writer() {
    while (true) {
        semWait(flag);
        semWait(wDataMutex);    // 写者这操作之间互斥，进入临界区
        write();
        semSignal(wDataMutex);  // 离开临界区
        semSignal(flag);
    }
}

void reader() {
    while (true) {
        semWait(flag);
        semWait(rCountMutex);
        ++rCount;
        if (1 == rCount) {
            semWait(wDataMutex);
        }
        semSignal(rCountMutex);
        semSignal(flag);

        read();

        semWait(rCountMutex);
        --rCount;
        if (0 == rCount) {
            semSignal(wDataMutex);  // 当没有读者了，则唤醒阻塞中的
        }
        semSignal(rCountMutex);
    }
}