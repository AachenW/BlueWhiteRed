#include <vector>
#include <iostream>
#include <algorithm>
/*
@
LeetCode 剑指offerⅡ
time: 2021-12-22 22:29:51
author: edinw
@
*/

/*
// 本题与主站 15 题相同：https://leetcode-cn.com/problems/3sum/
// 给你一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c ，使得 a + b + c = 0 ？请你找出所有和为 0 且不重复的三元组。
// 注意：答案中不可以包含重复的三元组。
*/

namespace leetcode_cpp{
class Solution{
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        decltype(nums.size())nLength = nums.size();
        if (nLength < 3) {
            return {};
        }
        std::sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> ans;
        // 枚举first
        for (decltype(nLength)first = 0; first < nLength; ++first) {
            // 跳过所有与first相等的数
            if (first > 0 && nums[first] == nums[first - 1]) {
                continue;
            }
            // third对应的指针初始值指向数组的最右端
            int target = -nums[first];
            decltype(nLength)third = nLength - 1;
            // 枚举second
            for (decltype(nLength)second = first + 1; second < nLength; ++second) {
                // 跳过所有与second相等的数
                if (second > first + 1 && nums[second] == nums[second - 1]) {
                    continue;
                }
                // 寻找满足条件的third
                while (second < third && nums[second] + nums[third] > target) {
                    --third;
                }
                if (second == third) {
                    break;
                }
                // 再次判断条件
                if (nums[second] + nums[third] == target) {
                    ans.push_back({nums[first], nums[second], nums[third]});
                }
            }
        }

        return ans;
    }
};   
}