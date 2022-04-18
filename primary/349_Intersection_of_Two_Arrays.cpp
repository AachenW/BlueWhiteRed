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
        std::unordered_set<int> cnt;
        for (int num: nums1) {
            cnt.insert(num);
        }

        std::vector<int> ans;
        for (int num: nums2) {
            if (cnt.count(num)) {
                cnt.erase(num);
                ans.emplace_back(num);
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