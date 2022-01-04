#include <vector>
#include <iostream>
#include <algorithm>
#include <limits.h>
/*
@
LeetCode 剑指offerⅡ
time: 2021-12-24 11:20:46
author: edinw
@
*/

/*
// 本题与主站 209 题相同：https://leetcode-cn.com/problems/minimum-size-subarray-sum/
// 给定一个含有 n 个正整数的数组和一个正整数 target. 
// 找出该数组中满足其和 ≥ target的长度最小的连续子数组[numsl, numsl+1, ..., numsr-1, numsr],并返回其长度.如果不存在符合条件的子数组,返回0.
*/

namespace leetcode_cpp {
class Solution{
public:
    int minSubArrayLen(int s, std::vector<int> &nums) {
        typedef decltype(nums.size()) sz;
        sz nLength = nums.size();
        if (0 == nLength) {
            return 0;
        }
        sz ans = UINT_MAX;
        sz start = 0, end = 0;
        int sum = 0;
        while (end < nLength) {
            sum += nums.at(end);
            while (sum >= s) {
                ans = std::min(ans, end - start + 1);
                sum -= nums.at(start);
                ++start;
            }
            ++end;
        }
        return ans == UINT_MAX ? 0 : ans;
    }

public:
    int lowerBound(std::vector<int> &a, int l, int r, int target) {
        int mid = -1, originL = l, originR = r;
        while (l < r) {
            mid = (l + r) >> 1;
            if (a[mid] < target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }
        return (a[l] >= target) ? l : -1;
    }
};
}

int main(int argc, char **argv) {
    int target = 7;
    std::vector<int> nums{2, 3, 1, 2, 4, 3};
    std::cout << leetcode_cpp::Solution().minSubArrayLen(target, nums) << std::endl;
    //std::cout << leetcode_cpp::Solution().lowerBound(nums, 0, nums.size() - 1, 2);
    return 0;
}