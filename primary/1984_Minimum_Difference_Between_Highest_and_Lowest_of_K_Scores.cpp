#include <iostream>
#include <vector>
#include <algorithm>
#include "limits.h"
/*
@
project: Leetcode
time: 2022-02-11 20:13:11
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int minimumDifference(std::vector<int> &nums, int k) {
        // 排序
        std::sort(nums.begin(), nums.end());
        int nLen = nums.size();
        int minAns = INT_MAX;
        for (int i = 0; i + k - 1 < nLen; ++i) {
            minAns = std::min(minAns, nums[i + k - 1] - nums[i]);
        }
        return  minAns;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums{9, 4, 1, 7};
    int k = 2;
    std::cout << leetcode_cpp::Solution().minimumDifference(nums, k) << std::endl;
    return 0;
}