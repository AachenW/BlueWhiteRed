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
本题与主站 198 题相同： https://leetcode-cn.com/problems/house-robber/
一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金, 影响小偷偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统,如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
给定一个代表每个房屋存放金额的非负整数数组 nums ，请计算 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。
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