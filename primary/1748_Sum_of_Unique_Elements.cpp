#include <iostream>
#include <vector>
#include "limits.h"
#include <unordered_map>
/*
@
project: Leetcode
time: 2022-02-06 18:59:16
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int sumOfUnique(std::vector<int> &nums) {
        std::unordered_map<int, int> cntMap;
        for (const auto &num: nums) {
            ++cntMap[num];
        }

        int ans = 0;
        for (const auto &num: nums) {
            if (1 == cntMap[num]) {
                ans += num;
            }
        }

        return ans;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums{1,2,3,4,5};
    std::cout << leetcode_cpp::Solution().sumOfUnique(nums) << std::endl;
    return 0;
}