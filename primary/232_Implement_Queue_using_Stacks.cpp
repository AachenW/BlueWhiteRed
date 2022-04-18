#include <vector>
#include <iostream>

/*
@
projetc: leetcode
time: 2022-03-16 12:01:32
author: edinw
@
*/

namespace leetcode_cpp {
class MyQueue {
public:
    MyQueue() {
        while (!stk.empty()) {
            stk.pop_back();
        }

        while (!stk_aux.empty()) {
            stk_aux.pop_back();
        }
    }
    
    void push(int x) {
        stk.emplace_back(x);
    }
    
    int pop() {
        if (stk_aux.empty()) {
            while (!stk.empty()) {
                stk_aux.emplace_back(stk.back());
                stk.pop_back();
            }
        }

        int ans = -1;
        if (!stk_aux.empty()) {
            ans = stk_aux.back();
            stk_aux.pop_back();
        }

        return ans;
    }
    
    int peek() {
        if (stk_aux.empty()) {
            while (!stk.empty()) {
                stk_aux.emplace_back(stk.back());
                stk.pop_back();
            }
        }

        return stk_aux.empty() ? -1 : stk_aux.back();
    }
    
    bool empty() {
        return stk.empty() && stk_aux.empty();
    }

private:
    std::vector<int> stk;
    std::vector<int> stk_aux;
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
}