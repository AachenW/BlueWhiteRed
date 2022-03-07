#include <vector>
#include <iostream>
#include <unordered_map>

/*
@
LeetCode 剑指offerII
time: 2022-03-04 15:03:38
author: edinw
@
*/

/*
**
**  Given an integer array nums where every element appears three times except for one, which appears exactly 
**      once. Find the single element and return it.
**
**  You must implement a solution with a linear runtime complexity and use only constant extra space.
*/

namespace leetcode_cpp {
class Solution {
public:
    int singleNumber(std::vector<int>& nums) {
        int ans = 0;

        for (int i = 0; i < 32; ++i) {
            int total = 0;
            for (const int num: nums) {
                total += (num >> i) & 1;
            }
            if (total % 3) {
                ans |= (1 << i);
            }
        }

        return ans;
    }
};

class Solution2 {
public:
    int singleNumber(std::vector<int>& nums) {
        std::unordered_map<int, int> freq;
        for (const auto &num : nums) {
            ++freq[num];
        }

        int ans = 0;
        for (const auto &item : freq) {
            if (item.second == 1) {
                ans = item.first;
                break;
            }
        }
        return ans;
    }
};
}