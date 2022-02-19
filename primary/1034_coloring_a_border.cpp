#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <ctime>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cstdlib>
#include <numeric>

/*
@
time: 2021-12-07 20:12:42
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    std::vector<std::vector<int>> colorBorder(std::vector<std::vector<int>>& grid, int row, int col, int color) {
        m = grid.size(), n = grid[0].size();
        vis = std::vector<std::vector<int>>(m, std::vector<int>(n, 0));
        int target = grid[row][col];
        dfs(grid, row, col, target);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0) {
                    grid[i][j] = color;
                }
            }
        }
        return grid;
    }

private:
    void dfs(std::vector<std::vector<int>>& grid, int x, int y, int color) {
        if (vis[x][y]) {
            return; // 已访问，直接返回
        }
        vis[x][y] = 1;  // 访问(x, y)
        if (grid[x][y] != color) {
            return; // 当前访问点与连通点着色不同，直接返回
        }

        int cnt = 0;
        for (int i = 0; i < 4; ++i) {   // 从(x, y)扩展到(nx, ny)
            int nx = x + dx[i], ny = y + dy[i]; // 表示在当前点分别向四个方向移动
            if (nx >= 0 && nx < m && ny >= 0 && ny < n) { // 搜索的点没超过矩阵边界
                if (grid[nx][ny] == color || grid[nx][ny] == 0) {   // 满足边界点或连通点
                    ++cnt;
                    dfs(grid, nx, ny, color);
                }
            }
        }
        if (cnt != 4) {
            grid[x][y] = 0;
        }
    }

    std::vector<std::vector<int>> vis;    // 0:未搜，1：已搜 2：已搜且为边界
    int dx[4] = {0,-1,0,1};
    int dy[4] = {1,0,-1,0};
    int n, m;

};
}

int main(int argc, char** argv) {
    std::vector<std::vector<int>> grid1{{1, 1, 1, 2, 2}, {2, 1, 2, 2, 2}, {1, 1, 2, 2, 1}};
    int row = 1, col = 0, color = 1;
    int m = grid1.size(), n = grid1[0].size();
    std::vector<std::vector<int>> ans = leetcode_cpp::Solution().colorBorder(grid1, row, col, color);
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << ans[i][j] << "\t";
        }
        std::cout << std::endl;
    }
}