#include <vector>
#include <string>
#include <iostream>
#include <deque>

/*
@
LeetCode 剑指offer
time: 2022-02-04 20:43:42
author: edinw
@
*/

/*
**  写一个函数，输入 n ，求斐波那契（Fibonacci）数列的第 n 项（即 F(N)）
*/

namespace leetcode_cpp {
class Solution {
public:
    int fib(int n) {
        if (0 == n) {
            return 0;
        }
        if (1 == n) {
            return 1;
        }
        int prev = 0, curr = 1;
        while (n-- > 1) {
            int next = (prev + curr) % (int)(1e9+7);
            prev = curr;
            curr = next;
        }
        return curr;
    }
};
}

int main(int argc, char **argv) {
    int n = 5;
    std::cout << leetcode_cpp::Solution().fib(n) << std::endl;
    return 0;
}