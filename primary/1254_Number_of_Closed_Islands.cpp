#include <bits/stdc++.h>

namespace leetcode_cpp {
class Solution {
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    int closedIsland(std::vector<std::vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        std::function<void(int, int)> backtrack = [&] (int x, int y) -> void {
            if (x < 0 || x >= rows || y < 0 || y >= cols || 1 == grid[x][y]) {
                return;
            }

            grid[x][y] = 1;
            for (auto &&dir: dirs) {
                int newX = x + dir[0];
                int newY = y + dir[1];
                backtrack(newX, newY);
            }
        };

        // 先把周围的不封闭的点处理掉
        for (int i = 0; i < rows; ++i) {
            backtrack(i, 0);
            backtrack(i, cols - 1);
        }
        // 先把周围的不封闭的点处理掉
        for (int j = 0; j < cols; ++j) {
            backtrack(0, j);
            backtrack(rows - 1, j);
        }

        int ans = 0;
        for (int i = 1; i < rows - 1; ++i) {
            for (int j = 1; j < cols - 1; ++j) {
                if (0 == grid[i][j]) {
                    backtrack(i, j);
                    ++ans;
                }
            }
        }

        return ans;
    }
};
}