#include <bits/stdc++.h>

/*
@
project: leetcode
time: 2022-03-30 09:04:00
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    bool PredictTheWinner(std::vector<int> &nums) {
        std::function<int(int, int, int)> total = [&] (int start, int end, int turn) -> int {
            if (start == end) {
                return nums[start] * turn;
            }

            int scoreStart = nums[start] * turn + total(start + 1, end, -turn);
            int scoreEnd = nums[end] * turn + total(start, end - 1, -turn);
            if (1 == turn) {
                return std::max(scoreStart, scoreEnd);
            } else {
                return std::min(scoreStart, scoreEnd);
            }
        };

        return total(0, nums.size() - 1, 1) >= 0;
    }
};

class Solution {
public:
    bool PredictTheWinner(std::vector<int> &nums) {
        int nSize = nums.size();
        // dp[i][j] 表示当数组剩下的部分为下标 i 到下标 j 时，即在下标范围 [i, j] 中，当前玩家与另一个玩家的分数之差的最大值，注意当前玩家不一定是先手。
        std::vector<std::vector<int>> dp(nSize, std::vector<int>(nSize));

        // 当 i=j 时，只剩一个数字，当前玩家只能拿取这个数字，因此对于所有 0≤i<nums.length，都有 dp[i][i] = nums[i]。
        for (int i = 0; i < nSize; i++) {
            dp[i][i] = nums[i];
        }
        for (int i = nSize - 2; i >= 0; i--) {
            for (int j = i + 1; j < nSize; j++) {
                // 当 i<j 时，当前玩家可以选择 nums[i] 或 nums[j]，然后轮到另一个玩家在数组剩下的部分选取数字。在两种方案中，当前玩家会选择最优的方案，使得自己的分数最大化。因此可以得到如下状态转移方程：
                dp[i][j] = std::max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
            }
        }
        return dp[0][nSize - 1] >= 0;
    }
};
}