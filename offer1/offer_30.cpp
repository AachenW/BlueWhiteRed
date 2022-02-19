#include <vector>
#include <iostream>
#include <deque>
#include "limits.h"
/*
@
LeetCode 剑指offer
time: 2022-01-28 22:43:37
author: edinw
@
*/

/*
**  注意：本题与主站 155 题相同：https://leetcode-cn.com/problems/min-stack/
**
**  Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
**
**  Implement the MinStack class:
**      MinStack() initializes the stack object.
**      void push(int val) pushes the element val onto the stack.
**      void pop() removes the element on the top of the stack.
**      int top() gets the top element of the stack.
**      int getMin() retrieves the minimum element in the stack.
*/

namespace leetcode_cpp {
class MinStack {
    std::deque<int> stack1;
    std::deque<int> stack2;
public:
    /** initialize your data structure here. */
    MinStack() {
        stack2.emplace_back(INT_MAX);
    }
    
    void push(int x) {
        stack1.emplace_back(x);
        stack2.emplace_back(std::min(x, stack2.back()));
    }
    
    void pop() {
        if (!stack1.empty()) {
            stack1.pop_back();
            stack2.pop_back();
        }
    }
    
    int top() {
        return stack1.back();
    }
    
    int min() {
        return stack2.back();
    }
};
}


/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->min();
 */

int main(int argc, char **argv) {
    auto minStack = new leetcode_cpp::MinStack();
    minStack->push(2147483646);
    minStack->push(2147483646);
    minStack->push(2147483647);
    std::cout << minStack->top() << std::endl;
    minStack->pop();
    std::cout << minStack->min() << std::endl;
    minStack->pop();
    std::cout << minStack->min() << std::endl;
    minStack->pop();
    minStack->push(2147483647);
    std::cout << minStack->top() << std::endl;
    std::cout << minStack->min() << std::endl;
    minStack->push(-2147483648);
    std::cout << minStack->top() << std::endl;
    std::cout << minStack->min() << std::endl;
    minStack->pop();
    std::cout << minStack->min() << std::endl;
    return 0;
}