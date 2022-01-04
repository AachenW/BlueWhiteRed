#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <ctime>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cstdlib>
#include <numeric>

/*
@
time: 2021-12-08 20:37:51
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    std::vector<int> maxSumOfThreeSubarrays(std::vector<int> &nums, int k) {
        std::vector<int> ans;
        int nLength = nums.size();
        int sum1 = 0, maxSum1 = 0, maxSum1Idx = 0;
        int sum2 = 0, maxSum12 = 0, maxSum12Idx1 = 0, maxSum12Idx2 = 0;
        int sum3 = 0, maxSum123 = 0;
        for (int i = k * 2; i < nLength; ++i) {
            sum1 += nums[i - k * 2];        // 第一个滑动窗口从[0, k-1]开始,滑动窗口右边界扩张
            sum2 += nums[i - k];            // 第一个滑动窗口从[k, 2k-1]开始,滑动窗口右边界扩张
            sum3 += nums[i];                // 第一个滑动窗口从[2k, 3k-1]开始,滑动窗口右边界扩张
            if (i >= 3 * k - 1) {
                if (sum1 > maxSum1) {
                    maxSum1 = sum1;                 // 更新第一个窗口最大值
                    maxSum1Idx = i - k * 3 + 1;     // 更新第一个窗口最大值对应的起始位置
                }
                if (maxSum1 + sum2 > maxSum12) {
                    maxSum12 = maxSum1 + sum2;      // 更新前两个窗口累计和的最大值
                    maxSum12Idx1 = maxSum1Idx;      // 同时更新前两个窗口取最大值时分别对应的起始位置
                    maxSum12Idx2 = i - k * 2 + 1;
                }
                if (maxSum12 + sum3 > maxSum123) {
                    maxSum123 = maxSum12 + sum3;    // 更新三个窗口累计和的最大值
                    ans = {maxSum12Idx1, maxSum12Idx2, i - k + 1};  // 更新当前三个窗口的起始位置
                }
                sum1 -= nums[i - k * 3 + 1];    // 滑动窗口左边界缩减
                sum2 -= nums[i - k * 2 + 1];    // 滑动窗口左边界缩减
                sum3 -= nums[i - k + 1];        // 滑动窗口左边界缩减
            }
        }
        return ans;
    }
private:
    std::vector<int> maxSumOfTwoSubarray(std::vector<int> &nums, int k) {
        std::vector<int> ans;
        int nLength = nums.size();
        int sum1 = 0, maxSum1 = 0, maxSum1Idx = 0;
        int sum2 = 0, maxSum12 = 0;
        for (int i = k; i < nLength; i++) {
            sum1 += nums[i - k];    // 第一个滑动窗口从[0, k-1]开始
            sum2 += nums[i];        // 第二个滑动窗口从[k, 2*k-1]开始
            if (i >= 2 * k - 1) {
                if (sum1 > maxSum1) {
                    maxSum1 = sum1;
                    maxSum1Idx = i - k * 2 + 1;
                }
                if (maxSum1 + sum2 > maxSum12) {
                    maxSum12 = maxSum1 + sum2;
                    ans = {maxSum1Idx, i - k + 1};
                }
                sum1 -= nums[i - 2 * k + 1];
                sum2 -= nums[i - k + 1];
            }
        }
        return ans;
    }

    std::vector<int> maxSumOfOneSubarray(std::vector<int> &nums, int k) {
        std::vector<int> ans;
        int nLength = nums.size();
        int sum1 = 0, maxSum1 = 0;
        for (int i = 0; i < nLength; ++i) {
            sum1 += nums[i];        // 滑动窗口右边界扩张
            if (i >= k - 1) {
                if (sum1 > maxSum1) {
                    maxSum1 = sum1;
                    ans = {i - k + 1};      // ans保存最大窗口对应的起始位置
                }
                sum1 -= nums[i - k + 1];    // 滑动窗口左边界缩减
            }
        }
        return ans;
    }
};
}

int main(int argc, char** argv) {
    std::vector<int> nums = {1,2,1,2,6,7,5,1};
    int target = 2;
    std::vector<int> ans = leetcode_cpp::Solution().maxSumOfThreeSubarrays(nums, target);
    for (int out: ans) {
        std::cout << out << "\t";
    }
}