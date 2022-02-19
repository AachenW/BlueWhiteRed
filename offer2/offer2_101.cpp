#include <vector>
#include <string>
#include <iostream>
#include <numeric>
#include <algorithm>
/*
@
LeetCode 剑指offerⅡ
time: 2022-01-11 21:23:09
author: edinw
@
*/

/*
注意：本题与主站 120 题相同： https://leetcode-cn.com/problems/triangle/

给定一个非空的正整数数组 nums ，请判断能否将这些数字分成元素和相等的两部分。
*/


namespace leetcode_cpp {
class Solution {
public:
    bool canPartition(std::vector<int> &nums) {
        int n = nums.size();
        if (n < 2) {
            return false;
        }
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        int maxNum = *max_element(nums.begin(), nums.end());
        if (sum & 1) {
            return false;
        }
        int target = sum / 2;
        if (maxNum > target) {
            return false;
        }
        auto dp = std::vector<std::vector<int>>(n, std::vector<int>(target + 1, 0));
        for (int i = 0; i < n; ++i) {
            dp[i][0] = true;
        }
        dp[0][nums[0]] = true;
        for (int i = 1; i < n; ++i) {
            int num = nums[i];
            for (int j = 1; j <= target; ++j) {
                if (j >= num) {             // num 可选可不选
                    dp[i][j] = dp[i - 1][j] | dp[i - 1][j - num];
                } else {                    // num 不能选
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n - 1][target];
    }
};

class Solution2 {
public:
    bool canPartition(std::vector<int> &nums) {
        int n = nums.size();
        if (n < 2) {
            return false;
        }
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1) {
            return false;
        }
        int target = sum / 2;
        int maxNum = *std::max_element(nums.begin(), nums.end());
        if (maxNum > target) {
            return false;
        }

        auto dp = std::vector<int>(target + 1, 0);
        dp[0] = true;
        dp[nums[0]] = true;
        for (int i = 1; i < n; ++i) {
            int num = nums.at(i);
            for (int j = target; j >= 0; --j) {
                if (j > num) {
                    dp[j] |= dp[j - num];
                }
            }
        }
        return dp[target];
    }
};
}

int main (int argc, char **argv) {
    std::vector<int> nums {1,5,11,5};
    std::cout << std::boolalpha << leetcode_cpp::Solution().canPartition(nums) << std::endl;
    return 0;
}