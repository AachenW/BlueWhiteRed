#include <bits/stdc++.h>

/*
@
project: leetcode
time: 2022-05-21 14:26:27
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int repeatedNTimes(std::vector<int> &nums) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int t = nums[i];
            if (i - 1 >= 0 && nums[i - 1] == t) return t;
            if (i - 2 >= 0 && nums[i - 2] == t) return t;
            if (i - 3 >= 0 && nums[i - 3] == t) return t;
        }
        return -1;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums{5, 1, 5, 2, 5, 3, 5, 4};
    std::cout << leetcode_cpp::Solution().repeatedNTimes(nums) << std::endl;
    return 0;
}