#include <vector>
#include "limits.h"
#include <iostream>

/*
@
project: Leetcode
time: 2022-02-26 09:53:26
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int maximumDifference(std::vector<int>& nums) {
        int maxDiff = INT_MIN;
        int nSize = nums.size();
        int lo = 0, hi = 0;

        while (lo < nSize) {
            hi = lo + 1;
            while (nums[lo] < nums[hi] && hi < nSize) {
                maxDiff = std::max(maxDiff, nums[hi] - nums[lo]);
                ++hi;
            }
            lo = hi;
        }

        return maxDiff == INT_MIN ? -1 : maxDiff;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums{7, 1, 5, 4};

    std::cout << leetcode_cpp::Solution().maximumDifference(nums) << std::endl;

    return 0;
}