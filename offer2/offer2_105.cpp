#include <vector>
#include <iostream>
#include <deque>
/*
@
LeetCode 剑指offerⅡ
time: 2022-01-13 22:16:25
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int maxAreaOfIsland(std::vector<std::vector<int>> &grid) {
        rows = grid.size();
        if (0 == rows) {
            return 0;
        }
        cols = grid.at(0).size();
        int ans = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                ans = std::max(ans, backtrack(grid, i, j));
            }
        }
        return ans;
    }

private:
    int backtrack(std::vector<std::vector<int>> &grid, int row, int col) {
        if (row < 0 || col < 0 || row == rows || col == cols || grid.at(row).at(col) != 1) {
            return 0;
        }
        grid.at(row).at(col) = 0;
        auto di = std::vector<int>{0, 0, 1, -1};
        auto dj = std::vector<int>{1, -1, 0, 0};
        int ans = 1;
        for (int index = 0; index < 4; ++index) {
            int nextRow = row + di.at(index);
            int nextCol = col + dj.at(index);
            ans += backtrack(grid, nextRow, nextCol);
        }
        return ans;
    }

private:
    int rows{0};
    int cols{0};
};

class Solution2{
public:
    int maxAreaOfIsland(std::vector<std::vector<int>> &grid) {
        rows = grid.size();
        if (0 == rows) {
            return 0;
        }
        cols = grid.at(0).size();
        int ans = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                int cur = 0;
                std::deque<int> queue_i;
                std::deque<int> queue_j;
                queue_i.push_back(i);
                queue_j.push_back(j);
                while (!queue_i.empty()) {
                    int row = queue_i.front();
                    int col = queue_j.front();
                    queue_i.pop_front();
                    queue_j.pop_front();
                    if (row < 0 || col < 0 || row == rows || col == cols || grid.at(row).at(col) != 1) {
                        continue;
                    }
                    grid.at(row).at(col) = 0;
                    ++cur;
                    std::vector<int> d_row{0, 0, -1, 1};
                    std::vector<int> d_col{1, -1, 0, 0};
                    for (int index = 0; index < 4; ++index) {
                        int nextRow = row + d_row.at(index);
                        int nextCol = col + d_col.at(index);
                        queue_i.push_back(nextRow);
                        queue_j.push_back(nextCol);
                    }
                }
                ans = std::max(cur, ans);
            }
        }
        return ans;
    }


private:
    int rows {0};
    int cols {0};
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