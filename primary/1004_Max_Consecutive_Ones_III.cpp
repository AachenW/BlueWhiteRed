#include <bits/stdc++.h>

/*
@
project: Leetcode
time: 2022-03-29 17:19:17
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int longestOnes(std::vector<int>& nums, int k) {
        int nSize = nums.size();
        int sum = 0, ans = 0;
        for (int left = 0, right = 0; right < nSize; ++right) {
            sum += nums[right] != 1;
            while (sum > k) {
                sum -= nums[left++] != 1;
            }
            ans = std::max(ans, right - left + 1);
        }

        return ans;
    }
};
}