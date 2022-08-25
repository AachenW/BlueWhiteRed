#include <bits/stdc++.h>

/*
@
projetc: leetcode
time: 2022-05-03 13:14:16 
author: edinw
@
*/

namespace leetcode_cpp {
class MyCircularQueue {
public:
    MyCircularQueue(int k) : n(k), front(0), rear(0), sz(0) {
        vec.clear();
        vec.resize(k);
    }

    bool enQueue(int value) {
        if (isFull()) return 0;
        vec[rear] = value;
        rear = (rear + 1) % n;
        ++sz;
        return 1;
    }

    bool deQueue() {
        if (isEmpty()) return 0;
        v[front] = -1;
        front = (front + 1) % n;
        --sz;
        return 1;
    }

    int Front() {
        if (isEmpty()) return -1;
        return vec[front];
    }

    int Rear() {
        if (isEmpty()) return -1;
        return vec[(rear - 1 + n) % n];
    }

    bool isEmpty() {
        return 0 == sz;
    }

    bool isFull() {
        return n == sz;
    }

private:
    std::vector<int> vec;
    int front, rear;
    int n, sz;
};
}

