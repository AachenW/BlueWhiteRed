#include <vector>
#include <string>
#include <iostream>
#include <deque>

/*
@
LeetCode 剑指offer
time: 2022-01-31 09:15:43
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int findRepeatNumber(std::vector<int> &nums) {
        int n = nums.size();
        std::vector<int> cnt(n + 1, 0);
        for (const auto &num: nums) {
            if (cnt[num]) {
                return num;
            }
            ++cnt[num];
        }
        return -1;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums {2, 3, 1, 0, 2, 5, 3};
    std::cout << leetcode_cpp::Solution().findRepeatNumber(nums) << std::endl;
    return 0;
}