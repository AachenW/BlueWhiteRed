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
projetc: leetcode
time: 2021-12-13 22:34:35
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int maxIncreaseKeepingSkyline(std::vector<std::vector<int>>& grid) {
        int nLength = grid.size();
        std::vector<int> rowMax(nLength);
        std::vector<int> colMax(nLength);

        for (int i = 0; i < nLength; ++i) {
            for (int j = 0; j < nLength; ++j) {
                rowMax[i] = std::max(rowMax[i], grid[i][j]);
                colMax[j] = std::max(colMax[j], grid[i][j]);
            }
        }

        int ans = 0;
        for (int i = 0; i < nLength; ++i) {
            for (int j = 0; j < nLength; ++j) {
                ans += std::min(rowMax[i], colMax[j]) - grid[i][j];
            }
        }
        return ans;
    }
};
}

int main(int argc, char** argv) {
    std::vector<std::vector<int>> grid {{3, 0, 8, 4},
                                        {2, 4, 5, 7},
                                        {9, 2, 6, 3},
                                        {0, 3, 1, 0}};
    std::cout << leetcode_cpp::Solution().maxIncreaseKeepingSkyline(grid) << std::endl;
}