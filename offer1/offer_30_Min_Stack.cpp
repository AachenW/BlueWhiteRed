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

class MinStack {
    // 我们每次存入的是 原来值 - 当前最小值。
    // 当原来值大于等于当前最小值的时候，我们存入的肯定就是非负数，所以出栈的时候就是 栈中的值 + 当前最小值 。
    // 当原来值小于当前最小值的时候，我们存入的肯定就是负值，此时的值我们不入栈，用 min 保存起来，同时将差值入栈。
public:
    /** initialize your data structure here. */
    MinStack() {
    }
    
    void push(int x) {
        if (stack.empty()) {
            stack.emplace_back(0);
            minValue = x;
        } else {
            // 数值没有限制的话，差值的计算可能会溢出。
            stack.emplace_back(x - minValue);
            if (x < minValue) {
                minValue = x;
            }
        }
    }
    
    void pop() {
        if (stack.empty()) {
            return;
        }

        long long pop = stack.back();
        stack.pop_back();
        if (pop < 0) {
            // 弹出的是负值, 说明之前对min值进行了更新。入栈元素 - min = 栈顶元素，入栈元素其实就是当前的min值，所以更新前的min就等于入栈元素-栈顶元素
            minValue = pop - minValue;
        }
    }
    
    int top() {
        long long top = stack.back();
        if (top < 0) {
            return (int)minValue;   // 负数的话，出栈的值保存在 min 中
        } else {
            return (int)(top + minValue);   // 出栈元素加上最小值即可
        }
    }
    
    int min() {
        return (int)minValue;
    }

private:
    long long minValue;
    std::deque<int> stack;
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