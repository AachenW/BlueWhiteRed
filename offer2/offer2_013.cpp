#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <numeric>
/*
@
LeetCode 剑指offerⅡ
time: 2021-12-26 19:14:29
author: edinw
@
*/

/*
本题与主站 304 题相同： https://leetcode-cn.com/problems/range-sum-query-2d-immutable/
二维子矩阵的和
*/

namespace leetcode_cpp {
class NumMatrix {
public:
    NumMatrix(std::vector<std::vector<int>> &matrix) {
        typedef decltype(matrix.size()) sz;
        sz m = matrix.size();
        if (m > 0) {
            sz n = matrix[0].size();
            sums.resize(m, std::vector<int>(n + 1));
            for (sz i = 0; i < m; ++i) {
                for (sz j = 0; j < n; ++j) {
                    sums[i][j + 1] = sums[i][j] + matrix[i][j]; // 第j+1列是前j行的前缀和
                }
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for (int i = row1; i <= row2; ++i) {
            sum += sums[i][col2 + 1] - sums[i][col1];           // sum[col1...col2] = presum[col2] - presum[col1 - 1]
        }
        return sum;
    }

public:
    std::vector<std::vector<int>> sums;
};
}