#include <vector>
#include <iostream>

/*
@
LeetCode 剑指offer
time: 2022-02-17 22:27:55
author: edinw
@
*/

/*
**  注意：本题与主站 169 题相同：https://leetcode-cn.com/problems/majority-element/
**
**  Given an array nums of size n, return the majority element.
**
**  The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.
*/

namespace leetcode_cpp {
class Solution {
public:
    int majorityElement(std::vector<int> &nums) {
        int candidate = 0, votes = 0;
        for (const int num: nums) {
            if (0 == votes) {
                candidate = num;
            }
            votes += num == candidate ? 1 : -1;
        }

        return candidate;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums{1, 2, 3, 2, 2, 2, 5, 4, 2};
    std::cout << leetcode_cpp::Solution().majorityElement(nums) << std::endl;
    return 0;
}