#include <bits/stdc++.h>

/*
@
LeetCode 剑指offerⅡ
time: 2022-03-29 17:39:13
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int leastBricks(std::vector<std::vector<int>> &wall) {
        std::unordered_map<int, int> cnt;
        for (auto &&widths: wall) {
            int n = widths.size();
            int sum = 0;
            for (int i = 0; i < n - 1; ++i) {
                sum += widths[i];
                ++cnt[sum];
            }
        }

        int maxCnt = 0;
        for (auto &[_, c]: cnt) {
            maxCnt = std::max(c, maxCnt);
        }

        return wall.size() - maxCnt;
    }
};
}