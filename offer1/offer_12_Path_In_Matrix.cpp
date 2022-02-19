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
    static constexpr int dirs[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    bool exist(std::vector<std::vector<char>> &board, std::string &word) {
        std::string combination;
        int flag = 0;
        rows = board.size();
        cols = board[0].size();
        if (0 == rows || 0 == cols) {
            return false;
        }
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                flag |= backtrack(board, word, i, j, 0);
                combination.clear();
            }
        }
        return flag;
    }

private:
    bool backtrack(std::vector<std::vector<char>> &board, std::string &word, int x, int y, int index) {
        if (board[x][y] != word[index]) {
            return false;
        } else if (index == word.length() - 1) {
            return true;
        }
        
        char originalChar = board[x][y];
        board[x][y] = ' ';
        
        int result = 0;
        for (int i = 0; i < 4; ++i) {
            int newX = x + dirs[i][0];
            int newY = y + dirs[i][1];
            if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && ' ' != board[newX][newY]) {
                int flag = backtrack(board, word, newX, newY, index + 1);
                if (flag) {
                    result = true;
                    break;
                }
            }
        }
        board[x][y] = originalChar;
        return result;
    }

private:
    int rows;
    int cols;
};

constexpr int Solution::dirs[4][2];
}

int main(int argc, char **argv) {
    std::vector<std::vector<char>> board{{'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
    std::string word {"ABCCED"};
    std::cout << leetcode_cpp::Solution().exist(board, word) << std::endl;
    return 0;
}