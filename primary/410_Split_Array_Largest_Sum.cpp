#include <vector>
#include <iostream>
#include "limits.h"

namespace leetcode_cpp {
class Solution {
public:
    int splitArray(std::vector<int>& nums, int m) {
        int nSize = nums.size();
        // dp[i][j] 表示将数组的前 i 个数分割为 j 段所能得到的最大连续子数组和的最小值
        std::vector<std::vector<int>> dp(nSize + 1, std::vector<int>(m + 1, INT_MAX));
        
        std::vector<int> prefix(nSize + 1);
        for (int i = 1; i <= nSize; ++i) {
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }

        dp[0][0] = 0;
        for (int i = 1; i <= nSize; ++i) {
            for (int j = 1; j <= std::min(i, m); ++j) {
                for (int k = 0; k < i; ++k) {
                    dp[i][j] = std::min(dp[i][j], std::max(dp[k][j - 1], prefix[i] - prefix[k]));
                }
            }
        }

        return dp[nSize][m];
    }
};
}