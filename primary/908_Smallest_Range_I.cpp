#include <bits/stdc++.h>

namespace leetcode_cpp {
class Solution {
public:
    int smallestRangeI(std::vector<int> &nums, int k) {
        int minNum = *std::min_element(nums.begin(), nums.end());
        int maxNum = *std::max_element(nums.begin(), nums.end());
        return maxNum - minNum <= 2 * k ? 0 : maxNum - minNum - 2 * k;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums{0, 10};
    int k = 2;
    std::cout << leetcode_cpp::Solution().smallestRangeI(nums, k) << std::endl;

    return 0;
}