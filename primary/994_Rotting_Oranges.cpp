#include <bits/stdc++.h>

namespace leetcode_cpp {
#include <bits/stdc++.h>

class Solution {
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    int orangesRotting(std::vector<std::vector<int>>& grid) {
        if (0 == grid.size() || 0 == grid[0].size()) {
            return 0;
        }

        int rows = grid.size(), cols = grid[0].size();
        int freshes = 0;
        std::deque<std::pair<int, int>> que;

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (1 == grid[i][j]) {
                    ++freshes;
                } else if (2 == grid[i][j]) {
                    que.emplace_back(i, j);
                }
            }
        } 

        int ans = 0;
        while (!que.empty()) {
            int qSize = que.size();
            int rotten = 0;
            for (int i = 0; i < qSize; ++i) {
                auto [x, y] = que.front(); que.pop_front();
                for (auto &&dir: dirs) {
                    int newX = x + dir[0];
                    int newY = y + dir[1];
                    if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && 1 == grid[newX][newY]) {
                        --freshes;
                        grid[newX][newY] = 2;
                        que.emplace_back(newX, newY);
                        rotten = 1;
                    }
                }        
            }
            if (rotten) {
                ++ans;
            }
        }

        return freshes ? -1 : ans;
    }
};
}