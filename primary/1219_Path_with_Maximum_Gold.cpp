#include <iostream>
#include <vector>
#include <functional>
/*
@
project: leetcode
time: 2022-02-05 20:11:19
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    int getMaximumGold(std::vector<std::vector<int>>  &grid) {
        int m = grid.size(), n = grid[0].size();
        int ans = 0;

        std::function<void(int, int, int)> backtrack = [&](int x, int y, int gold) {
            gold += grid[x][y];
            ans = std::max(ans, gold);

            int originalGold = grid[x][y];
            grid[x][y] = 0;

            for (int i = 0; i < 4; ++i) {
                int newX = x + dirs[i][0];
                int newY = y + dirs[i][1];
                if (newX >= 0 && newX < m && newY >= 0 && newY < n && grid[newX][newY] > 0) {
                    backtrack(newX, newY, gold);
                }
            }
            grid[x][y] = originalGold;
        };

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                backtrack(i, j, 0);
            }
        }
        return ans;
    }
};

constexpr int Solution::dirs[4][2];
}

int main(int argc, char **argv) {
    std::vector<std::vector<int>> grid {{1, 0, 7},
                                        {2, 0, 6},
                                        {3, 4, 5},
                                        {0, 3, 0},
                                        {9, 0, 20}};

    std::cout << leetcode_cpp::Solution().getMaximumGold(grid) << std::endl;
    return 0;
}