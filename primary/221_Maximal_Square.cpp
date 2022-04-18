#include <vector>
#include <iostream>

/*
@
projetc: leetcode
time: 2022-02-03 20:42:38
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int maximalSquare(std::vector<std::vector<char>> &matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        if (0 == rows || 0 == cols) {
            return 0;
        }

        std::vector<std::vector<int>> dp(rows, std::vector<int>(cols));
        int maxSide = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if ('1' == matrix[i][j]) {
                    if (0 == i || 0 == j) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = std::min(dp[i][j - 1], std::min(dp[i - 1][j], dp[i - 1][j - 1])) + 1;
                    }
                    maxSide = std::max(maxSide, dp[i][j]);
                }
            }
        }
        return maxSide * maxSide;
    }
};

class Solution {
public:
    int maximalSquare(std::vector<std::vector<char>> &matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        if (0 == rows || 0 == cols) {
            return 0;
        }

        std::vector<int> dp(cols);
        int left = 0, up = 0, left_up; 
        int maxSide = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (0 == i || 0 == j) {
                    left = dp[j];
                    dp[j] = matrix[i][j] - '0';
                } else if ('1' == matrix[i][j]) {
                    up = dp[j];
                    dp[j] = std::min(left, std::min(dp[j - 1], dp[j])) + 1;
                    left = up;
                } else {
                    dp[j] = 0;
                }
                maxSide = std::max(maxSide, dp[j]);
            }
        }

        return maxSide * maxSide;
    }
};
}

int main(int argc, char **argv) {
    std::vector<std::vector<char>> matrix {{'1', '0', '1', '0', '0'},
                                           {'1', '0', '1', '1', '1'},
                                           {'1', '1', '1', '1', '1'},
                                           {'1', '0', '0', '1', '0'}};
    std::cout << leetcode_cpp::Solution().maximalSquare(matrix) << std::endl;
    return 0;
}