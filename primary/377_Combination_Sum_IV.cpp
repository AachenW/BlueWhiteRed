#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include "limits.h"
/*
@
LeetCode 剑指offerⅡ
time: 2022-01-13 20:22:40
author: edinw
@
*/

/*
注意：本题与主站 377 题相同：https://leetcode-cn.com/problems/combination-sum-iv/

给定一个由 不同 正整数组成的数组 nums ，和一个目标整数 target 。请从 nums 中找出并返回总和为 target 的元素组合的个数。数组中的数字可以在一次排列中出现任意次，但是顺序不同的序列被视作不同的组合。

题目数据保证答案符合 32 位整数范围。
*/

namespace leetcode_cpp {
class Solution {
public:
    int combinationSum4(std::vector<int> &nums, int target) {
        // dp[x] 表示选取的元素之和等于 x 的方案数
        auto dp = std::vector<int>(target + 1, 0);
        // initialization, 只有当不选取任何元素时，元素之和才为 0
        dp[0] = 1;

        // states transfer
        int nLength = nums.size();
        for (int i = 1; i <= target; ++i) {
            for (const int &num: nums) {
                if (num <= i && dp[i - num] < INT_MAX - dp[i]) {
                    dp[i] += dp[i - num];
                }
            }
        }
        return dp[target];
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums {1, 2, 3};
    int target = 4;
    std::cout << leetcode_cpp::Solution().combinationSum4(nums, target) << std::endl;
    return 0;
}