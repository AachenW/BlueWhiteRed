#include <vector>
#include <string>
#include <iostream>
#include <deque>

/*
@
LeetCode 剑指offer
time: 2022-01-28 22:20:41
author: edinw
@
*/

/*
**  注意：本题与主站 155 题相同：https://leetcode-cn.com/problems/min-stack/
**
**  用两个栈实现一个队列。队列的声明如下，请实现它的两个函数 appendTail 和 deleteHead ，分别完成在队列尾部插入整数和在队列头部删除整数的功能。(若队列中没有元素，deleteHead 操
**      作返回 -1 )
*/

namespace leetcode_cpp {
class CQueue {
    std::deque<int> stack1;
    std::deque<int> stack2;
public:
    CQueue() {
        while (!stack1.empty()) {
            stack1.pop_back();
        }
        while (!stack2.empty()) {
            stack2.pop_back();
        }
    }

    void appendTail(int val) {
        stack1.emplace_back(val);
    }

    int deleteHead() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.emplace_back(stack1.back());
                stack1.pop_back();
            }
        }
        if (stack2.empty()) {
            return -1;
        }
        int ans = stack2.back();
        stack2.pop_back();
        return ans;
    }
};
}

int main(int argc, char **argv) {
    auto cQueue = new leetcode_cpp::CQueue();
    cQueue->appendTail(3);
    std::cout << cQueue->deleteHead() << std::endl;
    std::cout << cQueue->deleteHead() << std::endl;
    return 0;
}