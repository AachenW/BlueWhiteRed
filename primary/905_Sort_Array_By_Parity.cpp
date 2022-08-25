#include <bits/stdc++.h>

/*
@
projetc: leetcode
time: 2022-04-28 12:35:47 
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    std::vector<int> sortArrayByParity(std::vector<int> &nums) {
        int nSize = nums.size();
        int left = 0, right = nSize - 1;

        while (left < right) {
            while (left < right && !(nums[left] & 1)) ++left;
            while (left < right && (nums[right] & 1)) --right;
            std::swap(nums[left], nums[right]);
        }

        return nums;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums{3, 1, 2, 4};
    auto ans = leetcode_cpp::Solution().sortArrayByParity(nums);
    for (int num: ans) {
        std::cout << num << ",";
    }
    std::cout << std::endl;

    return 0;
}
