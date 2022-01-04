#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <numeric>
/*
@
LeetCode 剑指offerⅡ
time: 2021-12-26 19:14:29
author: edinw
@
*/

/*
 本题与主站 724 题相同： https://leetcode-cn.com/problems/find-pivot-index/
给你一个整数数组 nums ，请计算数组的 中心下标 。
数组 中心下标 是数组的一个下标，其左侧所有元素相加的和等于右侧所有元素相加的和。
如果中心下标位于数组最左端，那么左侧数之和视为 0 ，因为在下标的左侧不存在元素。这一点对于中心下标位于数组最右端同样适用。
如果数组有多个中心下标，应该返回 最靠近左边 的那一个。如果数组不存在中心下标，返回 -1 。
*/

namespace leetcode_cpp {
class Solution {
public:
    int pivotIndex(std::vector<int> &nums) {
        int total = std::accumulate(nums.begin(), nums.end(), 0);
        int sum = 0;
        typedef decltype(nums.size()) sz;
        sz nLength = nums.size();
        for (sz i = 0; i < nLength; ++i) {
            if (sum * 2 + nums[i] == total) {
                return i;
            } 
            sum += nums[i];
        }
        return -1;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums{1,7,3,6,5,6};
    int target = 3;
    std::cout << leetcode_cpp::Solution().pivotIndex(nums) << std::endl;
    return 0;
}