#include <bits/stdc++.h>

/*
@
projetc: leetcode
time: 2022-04-26 08:05:59
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int projectionArea(std::vector<std::vector<int>> &grid) {
        int n = grid.size();
        int xyArea = 0, yzArea = 0, zxArea = 0;
        for (int i = 0; i < n; i++) {
            int yzHeight = 0, zxHeight = 0;
            for (int j = 0; j < n; j++) {
                xyArea += grid[i][j] > 0 ? 1 : 0;
                yzHeight = std::max(yzHeight, grid[i][j]);
                zxHeight = std::max(zxHeight, grid[j][i]);
            }
            yzArea += yzHeight;
            zxArea += zxHeight;
        }
        return xyArea + yzArea + zxArea;
    }
};
}

int main(int argc, char **argv) {
    std::vector<std::vector<int>> grid{{1, 2}, {3, 4}};

    std::cout << leetcode_cpp::Solution().projectionArea(grid) << '\n';

    return 0;
}