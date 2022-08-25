#include <bits/stdc++.h>

namespace leetcode_cpp {
class Solution {
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    int numEnclaves(std::vector<std::vector<int>> &grid) {
        int rows = grid.size(), cols = grid[0].size();
        
        // std::vector<std::vector<int>> visited(rows, std::vector<int>(cols, 0));
        std::function<void(std::vector<std::vector<int>>&, int, int)> backtrack;
        backtrack = [&] (std::vector<std::vector<int>> &grid, int row, int col) {
            if (row < 0 || row >= rows || col < 0 || col >= cols || grid[row][col] == 0 || -1 == grid[row][col]) {
                return;
            }
            grid[row][col] = -1;
            for (const auto &dir: dirs) {
                backtrack(grid, row + dir[0], col + dir[1]);
            }
        };

        for (int i = 0; i < rows; ++i) {
            backtrack(grid, i, 0);
            backtrack(grid, i, cols - 1);
        }

        for (int j = 1; j < cols - 1; ++j) {
            backtrack(grid, 0, j);
            backtrack(grid, rows - 1, j);
        }

        int enclaves = 0;
        for (int i = 1; i < rows - 1; ++i) {
            for (int j = 1; j < cols - 1; ++j) {
                if (1 == grid[i][j]) {
                    ++enclaves;
                }
            }
        }

        return enclaves;
    }
};

constexpr int Solution::dirs[4][2];

class Solution2 {
public:
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    int numEnclaves(std::vector<std::vector<int>> &grid) {
        int rows = grid.size(), cols = grid[0].size();
        // std::vector<std::vector<int>> visited(rows, std::vector<int>(cols, 0));
        std::deque<std::pair<int, int>> que;

        for (int i = 0; i < rows; ++i) {
            if ( 1 == grid[i][0]) {
                que.emplace_back(i, 0);
                grid[i][0] = -1;
            }
            if (1 == grid[i][cols - 1]) {
                que.emplace_back(i, cols - 1);
                grid[i][cols - 1]  = -1;
            }
        }

        for (int j = 1; j < cols - 1; ++j) {
            if (1 == grid[0][j]) {
                que.emplace_back(0, j);
                grid[0][j] = -1;
            }
            if (1 == grid[rows - 1][j]) {
                que.emplace_back(rows - 1, j);
                grid[rows - 1][j] = -1;
            }
        }

        while (!que.empty()) {
            auto [row, col] = que.front();
            que.pop_front();
            for (const auto &dir: dirs) {
                int newRow = row + dir[0];
                int newCol = col + dir[1];
                if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && 1 == grid[newRow][newCol]) {
                    que.emplace_back(newRow, newCol);
                    grid[newRow][newCol] = -1;
                }
            }
        }

        int enclaves = 0;
        for (int i = 1; i < rows - 1; ++i) {
            for (int j = 1; j < cols - 1; ++j) {
                enclaves = 1 == grid[i][j] ? enclaves + 1: enclaves;
            }
        }

        return enclaves;
    }
};
}

int main(int argc, char **argv) {
    std::vector<std::vector<int>> grid{{0, 0, 0, 0}, {1, 0, 1, 0}, {0, 1, 1, 0}, {0, 0, 0, 0}};
    std::cout << leetcode_cpp::Solution().numEnclaves(grid) << std::endl;
    return 0;
}