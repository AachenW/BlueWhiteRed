#include <vector>
#include <string>
#include "limits.h"
#include <iostream>
/*
@
LeetCode 剑指offerII
time: 2022-03-04 19:14:12
author: edinw
@
*/

namespace leetcode_cpp {
class NumMatrix {
public:
    NumMatrix(std::vector<std::vector<int>> &matrix) {
        int rows = matrix.size(), cols = matrix[0].size();

        if (rows > 0) {
            sums.resize(rows, std::vector<int>(cols + 1));
            for (int i = 0; i < rows; ++i) {
                for (int j = 1; j <= cols; ++j) {
                    sums[i][j] = sums[i][j - 1] + matrix[i][j - 1];
                }
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int sum = 0;
        for (int i = row1; i <= row2; ++i) {
            sum += (sums[i][col2 + 1] - sums[i][col1]);
        }

        return sum;
    }

private:
    std::vector<std::vector<int>> sums;
};
}
