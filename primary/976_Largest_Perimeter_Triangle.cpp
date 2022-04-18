#include <vector>
#include <algorithm>
#include <iostream>

/*
@
project: leetcode
time: 2022-03-17 16:17:49
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int largestPerimeter(std::vector<int>& nums) {
        std::sort(nums.begin(), nums.end());
        for (int i = (int)nums.size() - 1; i >= 2; --i) {
            if (nums[i - 2] + nums[i - 1] > nums[i]) {
                return nums[i - 2] + nums[i - 1] + nums[i];
            }
        }
        return 0;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums{2, 1, 2};

    std::cout << leetcode_cpp::Solution().largestPerimeter(nums) << std::endl;
}