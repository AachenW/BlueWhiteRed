#include <iostream>
#include <vector>
#include <algorithm>

/*
@
projetc: leetcode
time: 2022-01-13 19:10:48
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int dominantIndex(std::vector<int> &nums) {
        int maxNum = *std::max_element(nums.begin(), nums.end());

        for (const auto &num: nums) {
            if (maxNum == num) {
                continue;
            }
            if (maxNum < 2 * num) {
                return -1;
            }
        }

        auto indexIt = std::find(nums.begin(), nums.end(), maxNum);
        return indexIt - nums.begin();
    }

};
}

int main(int argc, char **argv) {
    std::vector<int> nums {1};
    std::cout << leetcode_cpp::Solution().dominantIndex(nums) << std::endl;
    return 0;
}