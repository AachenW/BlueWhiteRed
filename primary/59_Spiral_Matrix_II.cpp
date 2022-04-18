#include <bits/stdc++.h>

/*
@
LeetCode
time: 2022-03-20 21:08:18
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    std::vector<std::vector<int>> generateMatrix(int n) {
        int left = 0, right = n - 1, top = 0, bottom = n - 1;
        std::vector<std::vector<int>> ans(n, std::vector<int>(n));
        int num = 1, target = n * n;
        while (num <= target) {
            for (int i = left; i <= right; ++i) {
                ans[top][i] = num++;
            }
            ++top;
            for (int i = top; i <= bottom; ++i) {
                ans[i][right] = num++;
            }
            --right;
            for (int i = right; i >= left; --i) {
                ans[bottom][i] = num++;
            }
            --bottom;
            for (int i = bottom; i >= top; --i) {
                ans[i][left] = num++;
            }
            ++left;
        }

        return ans;
    }
};
}
