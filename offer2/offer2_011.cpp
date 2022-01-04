#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
/*
@
LeetCode 剑指offerⅡ
time: 2021-12-26 19:14:29
author: edinw
@
*/

/*
// 本题与主站 525 题相同： https://leetcode-cn.com/problems/contiguous-array/
// 给定一个二进制数组 nums, 找到含有相同数量的0和1的最长连续子数组，并返回该子数组的长度。
*/

namespace leetcode_cpp {
class Solution{
public:
    int findMaxLength(std::vector<int> &nums) {
        // first: pre_sum, second: index when the pre_sum firstly occured.
        std::unordered_map<int, int> mp;
        int counter = 0;
        mp[counter] = -1;
        typedef decltype(nums.size()) sz;
        sz maxLength = 0, nLength = nums.size();
        for (sz i = 0; i < nLength; ++i) {
            int num = nums[i];
            if (num == 1) {
                ++counter;
            } else {
                --counter;
            }
            if (mp.count(counter)) {
                int prevIndex = mp[counter];
                maxLength = std::max(maxLength, i - prevIndex);
            } else {
                mp.at(counter) = i;
            }
        }
        return maxLength;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums {0, 1, 0};
    std::cout << leetcode_cpp::Solution().findMaxLength(nums) << std::endl;
    return 0;
}