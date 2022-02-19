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
**  注意：本题与主站 70 题相同：https://leetcode-cn.com/problems/climbing-stairs/
**
**  一只青蛙一次可以跳上1级台阶，也可以跳上2级台阶。求该青蛙跳上一个 n 级的台阶总共有多少种跳法。
**
**  答案需要取模 1e9+7（1000000007），如计算初始结果为：1000000008，请返回 1。
*/

namespace leetcode_cpp {
class Solution {
public:
    int numWays(int n) {
        if (n < 2) {
            return 1;
        }
        int prev = 1, curr = 1;
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
    int n = 44;
    std::cout << leetcode_cpp::Solution().numWays(n) << std::endl;
    return 0;
}