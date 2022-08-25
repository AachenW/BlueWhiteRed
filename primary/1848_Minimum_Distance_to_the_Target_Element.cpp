#include <bits/stdc++.h>

/*
@
project: Leetcode
time: 2022-04-23 14:02:41 
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int getMinDistance(std::vector<int> &nums, int target, int start) {
        int ans = INT_MAX, left = start, right = start;
        int nSize = nums.size();

        while (left >= 0 || right < nSize) {
            if (left >= 0 && nums[left] == target) {
                ans = std::min(ans, std::abs(start - left));
            }
            if (right < nSize && nums[right] == target) {
                ans = std::min(ans, std::abs(start - right));
            }
            --left;
            ++right;
        }

        return ans;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums{1, 2, 3, 4, 5};
    int target = 5, start = 3;

    std::cout << leetcode_cpp::Solution().getMinDistance(nums, target, start) << '\n';

    return 0;
}
