#include <vector>
#include <iostream>
#include <functional>
#include <deque>
/*
@
projetc: leetcode
time: 2022-02-14 23:54:27
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    int numIslands(std::vector<std::vector<char>> &grid) {
        int rows = grid.size(), cols = grid[0].size();
        if (0 == rows || 0 == cols) {
            return 0;
        }

        std::function<void(int, int)> backtrack;
        backtrack = [&](int row, int col) {
            grid[row][col] = '0';
            for (const auto &dir: dirs) {
                int newRow = row + dir[0];
                int newCol = col + dir[1];
                if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && '1' == grid[newRow][newCol]) {
                    backtrack(newRow, newCol);
                }
            }
        };

        int ans = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if ('1' == grid[i][j]) {
                    backtrack(i, j);
                    ++ans;
                }
            }
        }

        return ans;
    }
};

constexpr int Solution::dirs[4][2];

class Solution2 {
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    int numIslands(std::vector<std::vector<char>> &grid) {
        int rows = grid.size(), cols = grid[0].size();
        if (0 == rows || 0 == cols) {
            return 0;
        }

        int ans = 0;
        std::deque<std::pair<int, int>> que;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if ('1' == grid[i][j]) {
                    ++ans;
                    que.emplace_back(i, j);
                    grid[i][j] = '0';
                    while (!que.empty()) {
                        auto [row, col] = que.front();
                        que.pop_front();
                        for (const auto &dir: dirs) {
                            int newRow = row + dir[0];
                            int newCol = col + dir[1];
                            if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && '1' == grid[newRow][newCol]) {
                                que.emplace_back(newRow, newCol);
                                grid[newRow][newCol] = '0';
                            }
                        }
                    }
                }
            }
        }

        return ans;
    }
};
}

int main(int argc, char **argv) {
    std::vector<std::vector<char>> grid{{'1', '1', '1', '1', '0'},
                                        {'1', '1', '0', '1', '0'},
                                        {'1', '1', '0', '0', '0'},
                                        {'0', '0', '0', '0', '0'}};
    std::cout << leetcode_cpp::Solution2().numIslands(grid) << std::endl;
    
    return 0;
}