#include <vector>
#include <iostream>
#include <deque>
#include <functional>

/*
@
LeetCode 剑指offerⅡ
time: 2022-01-13 22:16:25
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    int maxAreaOfIsland(std::vector<std::vector<int>> &grid) {
        int rows = grid.size();
        if (0 == rows) {
            return 0;
        }
        int cols = grid.at(0).size();

        std::function<int(int, int)> backtrack = [&] (int x, int y) -> int{
            int ans = 1;

            grid[x][y] = 0;
            
            for (auto &&dir: dirs) {
                int newX = x + dir[0];
                int newY = y + dir[1];
                if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && 1 == grid[newX][newY]) {
                    ans += backtrack(newX, newY);
                }
            }

            return ans;
        };
        
        int ans = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (1 == grid[i][j]) {
                    ans = std::max(ans, backtrack(i, j));
                }
            }
        }
        return ans;
    }
};

class Solution2{
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    int maxAreaOfIsland(std::vector<std::vector<int>>& grid) {
        int rows = grid.size();
        if (0 == rows) {
            return 0;
        }
        int cols = grid.at(0).size();
        int ans = 0;
        std::deque<std::pair<int, int>> que;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (1 == grid[i][j]) {
                    int cur = 0;
                    que.emplace_back(i, j);
                    grid[i][j] = 0;
                    while (!que.empty()) {
                        auto [row, col] = que.front();
                        que.pop_front();
                        ++cur;
                        for (auto &&dir: dirs) {
                            int newRow = row + dir[0];
                            int newCol = col + dir[1];
                            if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && 1 == grid[newRow][newCol]) {
                                que.emplace_back(newRow, newCol);
                                grid[newRow][newCol] = 0;
                            }
                        }
                    }
                    ans = std::max(ans, cur);
                }
            }
        }
        return ans;
    }
};
}

int main(int argc, char **argv) {
    auto grid = std::vector<std::vector<int>>{{0,0,1,0,0,0,0,1,0,0,0,0,0},
                                              {0,0,0,0,0,0,0,1,1,1,0,0,0},
                                              {0,1,1,0,1,0,0,0,0,0,0,0,0},
                                              {0,1,0,0,1,1,0,0,1,0,1,0,0},
                                              {0,1,0,0,1,1,0,0,1,1,1,0,0},
                                              {0,0,0,0,0,0,0,0,0,0,1,0,0},
                                              {0,0,0,0,0,0,0,1,1,1,0,0,0},
                                              {0,0,0,0,0,0,0,1,1,0,0,0,0}};
    std::cout << leetcode_cpp::Solution2().maxAreaOfIsland(grid) << std::endl;
    return 0;

}