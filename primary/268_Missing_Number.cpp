#include <bits/stdc++.h>

/*
@
LeetCode
time: 2022-03-20 17:32:38
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int missingNumber(std::vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] != i) {
                return i;
            }
        }
        return n;
    }
};
}