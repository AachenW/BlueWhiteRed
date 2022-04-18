#include <bits/stdc++.h>

/*
@
project: Leetcode
time: 2022-04-04 17:09:18
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int longestSubarray(std::vector<int>& nums, int limit) {
        std::multiset<int> s;
        int n = nums.size();
        int ans = 0;

        for (int left = 0, right = 0; right < n; ++right) {
            s.insert(nums[right]);
            while (*s.rbegin() - *s.begin() > limit) {
                s.erase(s.find(nums[left++]));
            }
            ans = std::max(ans, right - left + 1);
        }

        return ans;
    }
};

class Solution2 {
public:
    int longestSubarray(std::vector<int> &nums, int limit) {
        std::deque<int> queMax, queMin;
        int n = nums.size();
        int ans = 0;
        
        for (int left = 0, right = 0; right < n; ++right) {
            while (!queMax.empty() && queMax.back() < nums[right]) {
                queMax.pop_back();
            }
            while (!queMin.empty() && queMin.back() > nums[right]) {
                queMin.pop_back();
            }
            queMax.emplace_back(nums[right]);
            queMin.emplace_back(nums[right]);

            while (!queMin.empty() && !queMax.empty() && queMax.front() - queMin.front() > limit) {
                if (nums[left] == queMin.front()) {
                    queMin.pop_front();
                }
                if (nums[left] == queMax.front()) {
                    queMax.pop_front();
                }
                ++left;
            }

            ans = std::max(ans, right - left + 1);
        }

        return ans;
    }
};
}