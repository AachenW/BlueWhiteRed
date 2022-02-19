#include <string>
#include <vector>
#include <iostream>
/*
@
LeetCode 剑指offerⅡ
time: 2022-01-04 23:08:14
author: edinw
@
*/


/*
注意：本题与主站 213 题相同： https://leetcode-cn.com/problems/house-robber-ii/

一个专业的小偷，计划偷窃一个环形街道上沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都 围成一圈 ，这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。

给定一个代表每个房屋存放金额的非负整数数组 nums ，请计算 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。
*/

namespace leetcode_cpp {
class Solution {
public:
    int rob(std::vector<int> &nums) {
        auto nLength = nums.size();
        if (1 == nLength) {
            return nums.at(0);
        } else if (2 == nLength) {
            return std::max(nums.at(0), nums.at(1));
        }
        // 如果不偷窃最后一间房屋，则偷窃房屋的下标范围是 [0, n-2]; 如果不偷窃第一间房屋，则偷窃房屋的下标范围是 [1, n-1]
        return std::max(robRange(nums, 0, nLength - 2), robRange(nums, 1, nLength - 1));
    }

private:
    int robRange(const std::vector<int> &nums, const int &start, const int &end) {
        // 考虑到每间房屋的最高总金额只和该房屋的前两间房屋的最高总金额相关，因此可以使用滚动数组，在每个时刻只需要存储前两间房屋的最高总金额
        int first = nums[start];
        int second = std::max(nums[start], nums[start + 1]);
        for (int i = start + 2; i <= end; ++i) {
            // 每一轮将dp数组向前滚动
            int temp = second;
            second = std::max(first + nums[i], second);
            first = temp;
        }
        return second;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums {1, 2, 3, 1};
    std::cout << leetcode_cpp::Solution().rob(nums) << std::endl;
    return 0;
}