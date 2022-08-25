#include <bits/stdc++.h>

/*
@
projetc: leetcode
time: 2022-04-27 10:39:33 
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    std::vector<std::vector<int>> pacificAtlantic(std::vector<std::vector<int>> &heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        std::vector<std::vector<int>> pacific(rows, std::vector<int>(cols, 0));
        std::vector<std::vector<int>> atlantic(rows, std::vector<int>(cols, 0));
        
        std::function<void(int, int, std::vector<std::vector<int>>&)> dfs = [&] (int row, int col, std::vector<std::vector<int>> &ocean) {
            if (ocean[row][col]) {
                return;
            }

            ocean[row][col] = 1;
            for (auto &&dir: dirs) {
                int newRow = row + dir[0];
                int newCol = col + dir[1];
                if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && heights[newRow][newCol] >= heights[row][col]) {
                    dfs(newRow, newCol, ocean);
                }
            }
        
        };

        for (int i = 0; i < rows; ++i) {
            dfs(i, 0, pacific);    
        }

        for (int j = 1; j < cols; ++j) {
            dfs(0, j, pacific);
        }

        for (int i = 0; i < rows; ++i) {
            dfs(i, cols - 1, atlantic);
        }

        for (int j = 0; j < cols - 1; ++j) {
            dfs(rows - 1, j, atlantic);
        }

        std::vector<std::vector<int>> ans;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};

class Solution2 {
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    std::vector<std::vector<int>> pacificAtlantic(std::vector<std::vector<int>> &heights) {
        int rows = heights.size();
        int cols = heights[0].size();
        std::vector<std::vector<int>> pacific(rows, std::vector<int>(cols, 0));
        std::vector<std::vector<int>> atlantic(rows, std::vector<int>(cols, 0));
        
        std::function<void(int, int, std::vector<std::vector<int>>&)> bfs = [&] (int row, int col, std::vector<std::vector<int>> &ocean) {
            if (ocean[row][col]) {
                return;
            }

            ocean[row][col] = 1;
            std::deque<std::pair<int, int>> que;
            que.emplace_back(row, col);

            while (!que.empty()) {
                auto [row, col] = que.front(); que.pop_front();
                for (auto &&dir: dirs) {
                    int newRow = row + dir[0], newCol = col + dir[1];
                    if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && heights[newRow][newCol] >= heights[row][col] && !ocean[newRow][newCol]) {
                        que.emplace_back(newRow, newCol);
                        ocean[newRow][newCol] = 1;
                    }
                }
            }
        };

        for (int i = 0; i < rows; ++i) {
            bfs(i, 0, pacific);    
        }

        for (int j = 1; j < cols; ++j) {
            bfs(0, j, pacific);
        }

        for (int i = 0; i < rows; ++i) {
            bfs(i, cols - 1, atlantic);
        }

        for (int j = 0; j < cols - 1; ++j) {
            bfs(rows - 1, j, atlantic);
        }

        std::vector<std::vector<int>> ans;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
       
};
}


int main(int argc, char **argv) {
    std::vector<std::vector<int>> heights{{1, 2, 2, 3, 5},
                                          {3, 2, 3, 4, 4},
                                          {2, 4, 5, 3, 1},
                                          {6, 7, 1, 4, 5},
                                          {5, 1, 1, 2, 4}};

    auto ans = leetcode_cpp::Solution2().pacificAtlantic(heights);
    for (auto &&vec: ans) {
        for (int num: vec) {
            std::cout << num << ",";
        }
        std::cout << '\n';
    }

    return 0;
}
