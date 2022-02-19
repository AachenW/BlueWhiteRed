#include <vector>
#include <iostream>
/*
@
LeetCode 剑指offer
time: 2022-02-05 21:13:49
author: edinw
@
*/

/*
**  在一个 m*n 的棋盘的每一格都放有一个礼物，每个礼物都有一定的价值（价值大于 0）。你可以从棋盘的左上角开始拿格子里的礼物，并每次向右或者向下移动一格、直到到达棋盘的右下角。给定一个** 棋盘及其上面的礼物的价值，请计算你最多能拿到多少价值的礼物？
*/

namespace leetcode_cpp {
class Solution {
public:
    int maxValue(std::vector<std::vector<int>> &grid) {
        int rows = grid.size(), cols = grid[0].size();
        if (0 == rows || 0 == cols) {
            return 0;
        }

        std::vector<int> dp(cols + 1, 0);
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                dp[j + 1] = std::max(dp[j], dp[j + 1]) + grid[i][j]; 
            }
        }
        return dp[cols];
    }
};
}

int main(int argc, char **argv) {
    std::vector<std::vector<int>> grid {{1, 3, 1},
                                        {1, 5, 1}, 
                                        {4, 2, 1}};
    std::cout << leetcode_cpp::Solution().maxValue(grid) << std::endl;
    return 0;
}