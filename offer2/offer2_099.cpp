#include <vector>
#include <string>
#include <iostream>

/*
@
LeetCode 剑指offerⅡ
time: 2022-01-10 21:58:41
author: edinw
@
*/

/*
注意：本题与主站 64 题相同： https://leetcode-cn.com/problems/minimum-path-sum/

给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

说明：一个机器人每次只能向下或者向右移动一步。
*/

namespace leetcode_cpp {
class Solution1 {
public:
    int minPathSum(std::vector<std::vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();
        if (m == 0 || n == 0) {
            return 0;
        }

        auto dp = std::vector<std::vector<int>>(m, std::vector<int>(n, 0));
        for (int i = 0; i < m; ++i) {
            dp[i][0] += grid[i][0];
        }
        for (int j = 0; j < n; ++j) {
            dp[0][j] += grid[0][j];
        }

        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[i][j] = std::min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[m - 1][n - 1];
    }
};
}

int main (int argc, char **argv) {
    std::vector<std::vector<int>> grid {{1, 3, 1}, {1, 5, 1}, {4, 2, 1}};
    std::cout << leetcode_cpp::Solution1().minPathSum(grid) << std::endl;
    return 0;
}