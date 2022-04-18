#include <iostream>
#include <vector>

/*
@
LeetCode 剑指offer
time: 2022-02-17 22:53:58
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int cuttingRope(int n) {
        std::vector<int> dp(n + 1);

        for (int i = 2; i < n; ++i) {
            int curMax = 0;
            for (int j = 1; j < i; ++j) {
                curMax = std::max(curMax, std::max(j * (i - j), j * dp[i - j]));
            }
            dp[i] = curMax;
        }

        return dp[n];
    }
};
}

int main(int argc, char **argv) {
    int n = 10;
    std::cout << leetcode_cpp::Solution().cuttingRope(n) << std::endl;
    return 0;
}