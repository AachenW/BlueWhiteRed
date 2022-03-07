#include <string>
#include <vector>
#include <iostream>
/*
@
LeetCode 剑指offerⅡ
time: 2021-12-24 10:41:26
author: edinw
@
*/


/*
**  本题与主站 198 题相同： https://leetcode-cn.com/problems/house-robber/
**
**  You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
**  
**  Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
*/

namespace leetcode_cpp {
class Solution{
public:
    int rob(std::vector<int> &nums) {
        decltype(nums.size()) nLength = nums.size();
        if (0 == nLength) {
            return 0;
        }
        if (1 == nLength) {
            return nums[0];
        }
        int first = nums[0], second = std::max(nums[0], nums[1]);
        for (decltype(nLength) i = 2; i < nLength; ++i) {
            int temp = second;
            second = std::max(first + nums[i], second);
            first = temp;
        }
        return second;
    }
};
}

int main(int argc, char **agrv) {
    std::vector<int> nums{2,7,9,3,1};
    std::cout << leetcode_cpp::Solution().rob(nums) << std::endl;
    return 0;
}