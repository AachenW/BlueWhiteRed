#include <vector>
#include <iostream>
#include "../lib/ListNode.h"
#include <algorithm>
/*
@
LeetCode 热题 HOT 100
time: 2022-02-14 23:35:30
author: edinw
@
*/

/*
**  Given an array nums of size n, return the majority element.
**
**  The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
*/

namespace leetcode_cpp {
class Solution {
public:
    int majorityElement(std::vector<int> &nums) {
        int nSize = nums.size();
        if (0 == nSize) {
            return -1;
        }
        int cnt = 1, ansNum = -1;
        for (const auto &num: nums) {
            if (num == ansNum) {
                ++cnt;
            } else if (--cnt < 0) {
                ansNum = num;
                cnt = 1;
            }
        }

        return ansNum;
    }
};

class Solution2 {
    int majorityElement(std::vector<int> &nums) {
        int nSize = nums.size();
        if (0 == nSize) {
            return -1;
        }
        std::sort(nums.begin(), nums.end());

        return nums[nSize >> 1];
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums{2,2,1,1,1,2,2};
    std::cout << leetcode_cpp::Solution().majorityElement(nums) << std::endl;
    
    return 0;
}