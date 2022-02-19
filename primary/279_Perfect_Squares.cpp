#include <vector>
#include <iostream>
#include <algorithm>
#include "limits.h"

/*
@
LeetCode
time: 2022-02-15 23:37:16
author: edinw
@
*/

/*
**  Given an integer n, return the least number of perfect square numbers that sum to n.
**
**  A perfect square is an integer that is the square of an integer; in other words, it is the product of some integer with itself. For example, 1, 4, 
**      9, and 16 are perfect squares while 3 and 11 are not.
*/

namespace leetcode_cpp {
class Solution {
public:
    int numSquares(int n) {
        if (0 == n) {
            return 0;
        }

        // initialization, dp[i] 表示最少需要多少个数的平方来表示整数 i
        std::vector<int> dp(n + 1);

        for (int i = 1; i <= n; ++i) {
            int minn = INT_MAX;
            for (int j = 1; j * j <= i; ++j) {
                minn = std::min(minn, dp[i - j * j]);
            }
            dp[i] = minn + 1;
        }
        return dp[n];
    }
};
}

int main(int argc, char **argv) {
    int n = 12;
    std::cout << leetcode_cpp::Solution().numSquares(n) << std::endl;
    return 0;
}