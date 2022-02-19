#include <vector>
#include <iostream>
#include <algorithm>
#include "limits.h"
#include "../lib/ListNode.h"

/*
@
LeetCode 剑指offer
time: 2022-02-09 20:31:51
author: edinw
@
*/

/*
**  输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有奇数在数组的前半部分，所有偶数在数组的后半部分。
*/

namespace leetcode_cpp {
class Solution {
public:
    std::vector<int> exchange(std::vector<int> &nums) {
        int lo = 0, hi = nums.size() - 1;
        while (lo < hi) {
            while (lo < hi && nums[lo] & 1) {
                ++lo;
            }
            while (lo < hi && !(nums[hi] & 1)) {
                --hi;
            }
            std::swap(nums[lo], nums[hi]);
        }
        return nums;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums {1, 2, 3, 4};
    leetcode_cpp::Solution().exchange(nums);
    for (const auto &num: nums) {
        std::cout << num << std::endl;
    }
    std::cout << std::endl;
    return 0;
}