#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
/*
@
LeetCode 剑指offer
time: 2022-02-19 21:54:41
author: edinw
@
*/

/*
**  请定义一个队列并实现函数 max_value 得到队列里的最大值，要求函数max_value、push_back 和 pop_front 的均摊时间复杂度都是O(1)。
**
**  若队列为空，pop_front 和 max_value 需要返回 -1
*/

namespace leetcode_cpp {
class MaxQueue {
public:
    MaxQueue() {
        
    }

    int max_value() {
        if (dque.empty()) {
            return -1;
        }
        return dque.front();
    }

    void push_back(int value) {
        while (!dque.empty() && dque.back() < value) {
            dque.pop_back();
        }
        dque.emplace_back(value);
        que.emplace(value);
    }

    int pop_front() {
        if (que.empty()) {
            return -1;
        }
        int ans = que.front();
        if (ans == dque.front()) {
            dque.pop_front();
        }
        que.pop();
        return ans;
    }

private:
    std::deque<int> dque;
    std::queue<int> que;
};
}