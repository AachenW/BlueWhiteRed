#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>
#include <math.h>
/*
@
LeetCode 剑指offerⅡ
time: 2021-12-24 11:20:46
author: edinw
@
*/

/*
// 本题与主站 713 题相同：https://leetcode-cn.com/problems/subarray-product-less-than-k/ 
// 给定一个正整数数组 nums和整数 k ，请找出该数组内乘积小于 k 的连续的子数组的个数。
*/

namespace leetcode_cpp {
class Solution {
public:
    int numSubarrayProductLessThanK(std::vector<int>& nums, int k) {
        if (0 == nums.size() || 0 == k || 1 == k) {
            return 0;
        }
        int lo = 0, hi = 0, ans = 0;
        decltype(nums.size()) nLength = nums.size();
        int sum = 1;
        while (hi < nLength) {
            sum *= nums[hi];
            while (sum >= k) {             // 如果当前窗口内乘积>=k, 则移动左窗口
                sum /= nums.at(lo);
                ++lo;
            }
            // 因为此时只要保持窗口右边界不动，窗口左边界形成的所有子数组的数字乘积就一定会小于k
            ans += hi - lo + 1;         // 如果当前窗口内乘积<k, 满足条件, 则两个指针之间有多少个数字，就找到了多少个数字乘积小于k的子数组
            ++hi;
        } 
        return ans;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums {10,9,10,4,3,8,3,3,6,2,10,10,9,3};
    int target = 19;
    std::cout << leetcode_cpp::Solution().numSubarrayProductLessThanK(nums, target) << std::endl;
    return 0;
}