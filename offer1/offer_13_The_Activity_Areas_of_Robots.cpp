#include <vector>
#include <iostream>
#include <algorithm>
#include "limits.h"
/*
@
LeetCode 剑指offer
time: 2022-02-10 17:04:00
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    int movingCount(int m, int n, int k) {
        if (0 == m || 0 == n) {
            return 0;
        }
        visited.resize(m, std::vector<int>(n));
        target = k;
        rows = m;
        cols = n;
        backtrack(0, 0);
        return cnt;
    }

private:
    void backtrack(int x, int y) {
        if (!check(x, y, target)) {
            return;
        }
        visited[x][y] = 1;
        ++cnt;
        for (int i = 0; i < 4; ++i) {
            int newX = x + dirs[i][0];
            int newY = y + dirs[i][1];
            if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && !visited[newX][newY]) {
                backtrack(newX, newY);
            }
        }
    }

    bool check(int x, int y, int k) {
        int sumRow = 0, sumCol = 0;
        while (x > 0) {
            sumRow += x % 10;
            x /= 10;
        }
        while (y > 0) {
            sumCol += y % 10;
            y /= 10;
        }
        return sumRow + sumCol <= k;
    }

private:
    int rows{0};
    int cols{0};
    int target{0};
    int cnt{0};
    std::vector<std::vector<int>> visited;
};

constexpr int Solution::dirs[4][2];
}

int main(int argc, char **argv) {
    int m = 2, n = 3, k = 1;
    std::cout << leetcode_cpp::Solution().movingCount(m, n, k) << std::endl;
    return 0;
}