#include <iostream>
#include <vector>
#include "limits.h"
/*
@
LeetCode HOT 100
time: 2022-02-05 21:38:12
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    bool canJump(std::vector<int> &nums) {
        int nLen = nums.size();
        if (0 == nLen) {
            return false;
        }

        int maxReach = 0;
        for (int i = 0; i < nLen; ++i) {
            if (i <= maxReach) {
                maxReach = std::max(maxReach, i + nums[i]);
            } else {
                return false;
            }
        }
        return true;
   }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums {3,2,1,0,4};
    std::cout << std::boolalpha << leetcode_cpp::Solution().canJump(nums) << std::endl;
    return 0;
}
