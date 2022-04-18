#include <vector>
#include <iostream>
#include <algorithm>
#include "limits.h"

/*
@
LeetCode
time: 2022-02-16 21:45:26
author: edinw
@
*/

/*
**  Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
**
**  Note that you must do this in-place without making a copy of the array.
*/

namespace leetcode_cpp {
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int nSize = nums.size();
        if (0 == nSize) {
            return;
        }

        int pos = 0;
        for (int num: nums) {
            if (0 != num) {
                nums[pos++] = num;
            }
        }

        for (int i = pos; i < nSize; ++i) {
            nums[i] = 0;
        }

        return;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums {0, 1, 0, 3, 12};
    leetcode_cpp::Solution().moveZeroes(nums);
    for (const int num: nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;
    return 0;
}