#include <bits/stdc++.h>

/*
@
project: Leetcode
time: 2022-04-20 13:59:12 
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    Solution(std::vector<int> &nums) {
        this->nums = nums;
        this->original.resize(nums.size());
        std::copy(nums.begin(), nums.end(), original.begin());
    }

    std::vector<int> reset() {
        copy(original.begin(), original.end(), nums.begin());
        return nums;
    }

    std::vector<int> shuffle() {
        for (int i = 0; i < nums.size(); ++i) {
            int j = i + rand() % (nums.size() - i);
            std::swap(nums[i], nums[j]);
        }
        return nums;
    }

private:
    std::vector<int> nums;
    std::vector<int> original;
};
}

