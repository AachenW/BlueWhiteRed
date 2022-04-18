#include <bits/stdc++.h>

/*
@
project: Leetcode
time: 2022-03-29 21:09:53
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    std::vector<int> smallerNumbersThanCurrent(std::vector<int>& nums) {
        int nSize = nums.size();
        int leftMin = INT_MAX;
        int count = 0;
        std::vector<int> ans(nSize);

        for (int i = 0; i < nSize; ++i) {
            count = 0;
            leftMin = std::min(leftMin, nums[i]);
            if (nums[i] > leftMin) {
                for (int j = i - 1; j >= 0; --j) {
                    if (nums[j] < nums[i]) {
                        ++count;
                    }
                }
            }

            for (int j = i + 1; j < nSize; ++j) {
                if (nums[j] < nums[i]) {
                    ++count;
                }
            }

            ans[i] = count;
        }

        return ans;
    }
};

class Solution2 {
public:
    std::vector<int> smallerNumbersThanCurrent(std::vector<int>& nums) {
        std::vector<int> cnt(101, 0);
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            cnt[nums[i]]++;
        }

        for (int i = 1; i <= 100; ++i) {
            cnt[i] += cnt[i - 1];
        }

        std::vector<int> ans;
        for (int i = 0; i < n; ++i) {
            ans.emplace_back(nums[i] == 0 ? 0 : cnt[nums[i] - 1]);
        }

        return ans;
    }
};
}