#include <bits/stdc++.h>

/*
@
LeetCode
time: 2022-03-24 11:58:44
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int uniquePathsWithObstacles(std::vector<std::vector<int>>& obstacleGrid) {
        if (0 == obstacleGrid.size() || 0 == obstacleGrid[0].size()) {
            return 0;
        }

        int rows = obstacleGrid.size(), cols = obstacleGrid[0].size();
        std::vector<std::vector<int>> dp(rows, std::vector<int>(cols));

        for (int j = 0; j < cols; ++j) {
            if (0 == obstacleGrid[0][j]) {
                dp[0][j] = 1;
            } else {
                break;
            }
        }
        for (int i = 1; i < rows; ++i) {
            if (0 == obstacleGrid[i][0]) {
                dp[i][0] += dp[i - 1][0];
            } else {
                break;
            }
        }

        for (int i = 1; i < rows; ++i) {
            for (int j = 1; j < cols; ++j) {
                if (obstacleGrid[i][j]) {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
                }
            }
        }

        return dp[rows - 1][cols - 1];
    }
};
}

int main(int argc, char **argv) {
    std::vector<std::vector<int>> obstacleGrid = {{0,0,0},{0,1,0},{0,0,0}};

    std::cout << leetcode_cpp::Solution().uniquePathsWithObstacles(obstacleGrid) << std::endl;

    return 0;
}