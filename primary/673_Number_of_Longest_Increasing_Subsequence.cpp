#include <bits/stdc++.h>

/*
@
projetc: leetcode
time: 2022-05-11 18:27:26 
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int findNumberOfLIS(std::vector<int> &nums) {
        int nSize = nums.size(), maxLen = 0, ans = 0;
        std::vector<int> dp(nSize), cnt(nSize);

        for (int i = 0; i < nSize; ++i) {
            dp[i] = 1;
            cnt[i] = 1;
            for (int j = 0; j < i; ++j) {
                if (nums[j] < nums[i]) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        cnt[i] = cnt[j];    // 重置奇数
                    } else if (dp[j] + 1 == dp[i]) {
                        cnt[i] += cnt[j];
                    }
                }
            }

            if (dp[i] > maxLen) {
                maxLen = dp[i];
                ans = cnt[i];
            } else if (dp[i] == maxLen) {
                ans += cnt[i];
            }
        }

        return ans;
    }
};
}


int main(int argc, char **argv) {
    std::vector<int> nums {1, 3, 5, 4, 7};
    std::cout << leetcode_cpp::Solution().findNumberOfLIS(nums) << std::endl;

    return 0;
}
