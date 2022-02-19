#include <iostream>
#include <vector>
#include "limits.h"
/*
@
LeetCode 剑指Offer
time: 2022-02-04 21:17:23
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int climbStairs(int n) {
        if (n < 2) {
            return 1;
        }
        int prev = 1, curr = 1;
        while (n-- > 1) {
            int next = prev + curr;
            prev = curr;
            curr = next;
        }
        return curr;
    }
};
}

int main(int argc, char **argv) {
    int n = 5;
    std::cout << leetcode_cpp::Solution().climbStairs(n) << std::endl;
    return 0;
}