#include <bits/stdc++.h>

/*
@
project: Leetcode
time: 2022-04-04 17:38:03
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    std::vector<int> findDiagonalOrder(std::vector<std::vector<int>>& nums) {
        if (0 == nums.size() || 0 == nums[0].size()) {
            return {};
        }

        int rows = nums.size();
        std::map<int, std::vector<int>> mp;
        // 使用map从最后一行开始存储列表元素, 利用map有序的特点;
        for (int i = rows - 1; i >= 0; --i) {
            for (int j = 0; j < nums[i].size(); ++j) {
                // 同一斜线元素满足下标(i+j)相等;
                mp[i + j].push_back(nums[i][j]);
            }
        }

        std::vector<int> ans;
        for (auto &[key, vec]: mp) {
            for (auto &&num: vec) {
                // 顺序输出map中的元素, 即为题目要求的输出;
                ans.emplace_back(num);
            }
        }

        return ans;
    }
};
}