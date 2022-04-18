#include <bits/stdc++.h>

/*
@
project: leetcode
time: 2022-03-28 18:45:38
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int maxSumDivThree(std::vector<int>& nums) {
        std::vector<int> dp(3);

        for (int num: nums) {
            int a = dp[0] + num;
            int b = dp[1] + num;
            int c = dp[2] + num;

            dp[a % 3] = std::max(dp[a % 3], a);
            dp[b % 3] = std::max(dp[b % 3], b);
            dp[c % 3] = std::max(dp[c % 3], c);
        }
        return dp[0];
    }
};
}
