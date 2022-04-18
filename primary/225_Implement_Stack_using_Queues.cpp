#include <bits/stdc++.h>


/*
@
projetc: leetcode
time: 2022-03-23 16:02:13
author: edinw
@
*/

namespace leetcode_cpp {
class MyStack {
public:
    MyStack() {

    }

    void push(int x) {
        que2.emplace_back(x);
        while (!que1.empty()) {
            que2.emplace_back(que1.front());
            que1.pop_front();
        }
        std::swap(que1, que2);
    }

    int pop() {
        int ans = que1.front(); que1.pop_front();
        return ans;
    }

    int top() {
        int ans = que1.front();
        return ans;
    }

    bool empty() {
        return que1.empty();
    }

private:
    std::deque<int> que1;
    std::deque<int> que2;
};
}