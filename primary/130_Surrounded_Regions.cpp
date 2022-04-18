#include <bits/stdc++.h>

/*
@
LeetCode
time: 2022-04-04 13:09:56
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
public:
    void solve(std::vector<std::vector<char>>& board) {
        if (0 == board.size() || 0 == board[0].size()) {
            return;
        }

        int rows = board.size(), cols = board[0].size();
        std::function<void(int, int)> backtrack = [&] (int x, int y) {
            if (x < 0 || x >= rows || y < 0 || y >= cols || 'N' == board[x][y] || 'X' == board[x][y]) {
                return;
            }

            board[x][y] = 'N';
            for (auto &&dir: dirs) {
                int newX = x + dir[0];
                int newY = y + dir[1];
                backtrack(newX, newY);
            }
        };

        for (int i = 0; i < rows; ++i) {
            backtrack(i, 0);
            backtrack(i, cols - 1);
        }

        for (int j = 0; j < cols; ++j) {
            backtrack(0, j);
            backtrack(rows - 1, j);
        }

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if ('N' == board[i][j]) {
                    board[i][j] = 'O';
                } else if ('O' == board[i][j]) {
                    board[i][j] = 'X';
                }
            }
        }

        return;
    }
};
}