#include <bits/stdc++.h>

/*
@
LeetCode
time: 2022-03-24 11:07:08
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    std::vector<int> intersection(std::vector<int>& nums1, std::vector<int>& nums2) {
        std::unordered_map<int, int> mp;
        for (int num: nums1) {
            ++mp[num];
        }

        std::vector<int> ans;
        for (int num: nums2) {
            if (mp.count(num)) {
                ans.emplace_back(num);
                --mp[num];
                if (0 == mp[num]) {
                    mp.erase(num);
                }
            }
        }

        return ans;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums1 {1, 2, 2, 1};
    std::vector<int> nums2 {2, 2};
}