#include <vector>
#include <string>
#include <iostream>
#include <numeric>
#include <algorithm>
/*
@
LeetCode 剑指offerⅡ
time: 2022-01-12 20:20:46
author: edinw
@
*/

/*
给定一个正整数数组 nums 和一个整数 target 。

向数组中的每个整数前添加 '+' 或 '-' ，然后串联起所有整数，可以构造一个 表达式 ：

例如，nums = [2, 1] ，可以在 2 之前添加 '+' ，在 1 之前添加 '-' ，然后串联起来得到表达式 "+2-1" 。
返回可以通过上述方法构造的、运算结果等于 target 的不同 表达式 的数目。
*/

namespace leetcode_cpp {
class Solution {
public:
    int findTargetSumWays (std::vector<int> &nums, int target) {
        backtrack(nums, target, 0, 0);
        return count;
    }

private:
    void backtrack(std::vector<int> &nums, int target, int index, int sum) {
        if (index == nums.size()) {
            if (sum == target) {
                ++count;
            }
        } else {
            backtrack(nums, target, index + 1, sum - nums.at(index));
            backtrack(nums, target, index + 1, sum + nums.at(index));
        }
    }
private:
    int count{0};
};

class Solution2 {
public:
    int findTargetSumWays(std::vector<int> &nums, int target) {
        int nLength = nums.size();
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        int maxNum = *std::max_element(nums.begin(), nums.end());
        int diff = sum - target;
        if (diff < 0 || diff & 2) {
            return 0;
        }
        int neg = diff / 2;
        if (maxNum > neg) {
            return 0;
        }

        // dp[i][j] 表示在数组 nums 的前 i 个数中选取元素，使得这些元素之和等于 j 的方案数
        auto dp = std::vector<std::vector<int>>(nLength + 1, std::vector<int>(neg + 1, 0));
        dp[0][0] = 1;
        dp[0][nums.at(0)] = 1;
        for (int i = 1; i <= nLength; ++i) {
            int num = nums.at(i);
            for (int j = 0; j <= neg; ++j) {
                if (j >= num) {
                    dp[i][j] += dp[i - 1][j] + dp[i - 1][j - num];
                } else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[nLength][neg];
    }
};

class Solution3 {
public:
    int findTargetSumWays(std::vector<int> &nums, int target) {
        int nLength = nums.size();
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        int maxNum = *std::max_element(nums.begin(), nums.end());
        int diff = sum - target;
        if (diff < 0 || diff & 2) {
            return 0;
        }
        int neg = diff / 2;
        if (maxNum > neg) {
            return 0;
        }

        auto dp = std::vector<int>(neg + 1, 0);
        dp[0] = 1;
        for (int i = 1; i < nLength; ++i) {
            int num = nums.at(i);
            for (int j = neg; j >= num; --j) {
                if (j > num) {
                    dp[j] += dp[j - num];
                }
            }
        }
        return dp[neg];
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums {1, 1, 1, 1, 1};
    int target = 3;
    std::cout << leetcode_cpp::Solution2().findTargetSumWays(nums, target) << std::endl;
    return 0;
}