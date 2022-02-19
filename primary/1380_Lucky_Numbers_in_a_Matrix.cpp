#include <vector>
#include <iostream>
#include "limits.h"

namespace leetcode_cpp {
class Solution {
public:
    std::vector<int> luckyNumbers(std::vector<std::vector<int>> &matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int maxMin = INT_MIN;
        for (int i = 0; i < m; ++i) {
            int min = INT_MAX;
            for (int j = 0; j < n; ++j) {
                min = std::min(min, matrix[i][j]);
            }
            maxMin = std::max(maxMin, min);
        }

        int minMax = INT_MAX;
        for (int j = 0; j < n; ++j) {
            int max = INT_MIN;
            for (int i = 0; i < m; ++i) {
                max = std::max(max, matrix[i][j]);
            }
            minMax = std::min(minMax, max);
        }

        if (minMax != maxMin) {
            return std::vector<int> {};
        }

        return std::vector<int> {maxMin};
    }
};

class Solution2 {
public:
    std::vector<int> luckyNumbers(std::vector<std::vector<int>> &matrix) {
        int m = matrix.size(), n = matrix[0].size();
        std::vector<int> minRow(m, INT_MAX), maxCol(n, INT_MIN);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                minRow[i] = std::min(minRow[i], matrix[i][j]);
                maxCol[j] = std::max(maxCol[j], matrix[i][j]);
            }
        }

        std::vector<int> ans;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == minRow[i] && matrix[i][j] == maxCol[j]) {
                    ans.emplace_back(matrix[i][j]);
                }
            }
        }

        return ans;
    }
};
}

int main(int argc, char **argv) {
    std::vector<std::vector<int>> matrix{{3, 7, 8}, {9, 11, 13}, {15, 16, 17}};
    auto ans = leetcode_cpp::Solution2().luckyNumbers(matrix);
    std::cout << ans[0] << std::endl;
    return 0;
}