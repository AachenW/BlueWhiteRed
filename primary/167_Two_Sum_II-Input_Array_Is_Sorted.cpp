#include <vector>
#include <string>
#include <iostream>

/*
@
LeetCode 剑指offerII
time: 2022-03-04 15:22:43
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& numbers, int target) {
        int nSize = numbers.size();
        int lo = 0, hi = nSize - 1;
        
        while (lo < hi) {
            int sum = numbers[lo] + numbers[hi];
            if (sum == target) {
                return {lo + 1, hi + 1};
            } else if (sum < target) {
                ++lo;
            } else {
                --hi;
            }
        }

        return {-1, -1};
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums {2, 3, 4};
    int target = 6;

    auto ans = leetcode_cpp::Solution().twoSum(nums, target);
    for (const int output: ans) {
        std::cout << output << ",";
    }
    std::cout << std::endl;
    
    return 0;
}
