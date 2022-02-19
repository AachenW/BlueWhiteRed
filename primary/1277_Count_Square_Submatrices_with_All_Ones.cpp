#include <vector>
#include <iostream>
#include <map>
/*
@
project: Leetcode
time: 2022-02-03 21:07:58
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int countSquares(std::vector<std::vector<int>> &matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        if (0 == rows || 0 == cols) {
            return 0;
        }
        std::vector<std::vector<int>> dp(rows, std::vector<int>(cols));
        int ans = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (1 == matrix[i][j]) {
                    if (0 == i || 0 == j) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = std::min(std::min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
                    }
                    ans += dp[i][j];
                }
            }
        }
        return ans;
    }
};
}

int main(int argc, char **argv) {
    std::vector<std::vector<int>> matrix{{0, 1, 1, 1},
                                         {1, 1, 1, 1},
                                         {0, 1, 1, 1}};
    std::cout << leetcode_cpp::Solution().countSquares(matrix) << std::endl;
    return 0;
}