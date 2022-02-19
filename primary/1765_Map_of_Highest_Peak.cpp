#include <iostream>
#include <vector>
#include <deque>
/*
@
project: Leetcode
time: 2022-01-30 19:43:56
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
    constexpr static int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    std::vector<std::vector<int>> highestPeak(std::vector<std::vector<int>> &isWater) {
        int m = isWater.size(), n = isWater[0].size();
        std::vector<std::vector<int>> ans(m, std::vector<int>(n, -1));
        std::deque<std::pair<int, int>> queue;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (isWater[i][j]) {
                    ans[i][j] = 0;
                    queue.emplace_back(i, j);
                }
            }
        }

        while (!queue.empty()) {
            auto [x, y] = queue.front();
            queue.pop_front();
            for (const auto &dir: dirs) {
                int newX = x + dir[0], newY = y + dir[1];
                if (0 <= newX && newX < m && 0 <= newY && newY < n && ans[newX][newY] == -1) {
                    ans[newX][newY] = ans[x][y] + 1;
                    queue.emplace_back(newX, newY);
                }
            }
            
        }
        return ans;
    }
};
}

int main(int argc, char **argv) {
    std::vector<std::vector<int>> isWater{{0, 0, 1}, {1, 0, 0}, {0, 0, 0}};
    auto ans = leetcode_cpp::Solution().highestPeak(isWater);
    for (const auto &nums: ans) {
        for (const auto &num: nums) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}