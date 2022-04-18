#include <bits/stdc++.h>

/*
@
projetc: leetcode
time: 2022-03-31 19:45:13
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    void setZeroes(std::vector<std::vector<int>>& matrix) {
        if (0 == matrix.size() || 0 == matrix[0].size()) {
            return;
        }

        int rows = matrix.size(), cols = matrix[0].size();
        std::vector<int> row0(rows);
        std::vector<int> col0(cols);

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (!matrix[i][j]) {
                    row0[i] = col0[j] = 1;
                }
            }
        }

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (row0[i] || col0[j]) {
                    matrix[i][j] = 0;
                }
            }
        }

        return;
    }
};
}