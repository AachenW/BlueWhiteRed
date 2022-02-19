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
time: 2021-12-09 20:34:44
author: edinw
@
*/

namespace leetcode_cpp {
class Solution{
public:
    bool validTicTacToe(std::vector<std::string>& board) {
        int xCount = 0, oCount = 0;
        for (std::string& row: board) {
            for (char c: row) {
                xCount = (c == 'X') ? (xCount + 1): xCount;
                oCount = (c == 'O') ? (oCount + 1): oCount;
            }
        }
        // 若X手(先手)胜，则棋盘上X的数量比O的数量多1枚
        // 若O手(后手)胜，则棋盘上O的数量=X的数量
        if (oCount != xCount && oCount != xCount - 1) {
            return false;
        }

        if (win(board, 'X') && oCount != xCount - 1) {
            return false;
        }
        if (win(board, 'O') && oCount != xCount) {
            return false;
        }
        return true;
    }

private:
    bool win(std::vector<std::string>& board, char p) {
        for (int i = 0; i < 3; ++i) {
            // 横向胜盘
            if (p == board[i][0] && p == board[i][1] && p == board[i][2]) {
                return true;
            }
            // 纵向胜盘
            if (p == board[0][i] && p == board[1][i] && p == board[2][i]) {
                return true;
            }
        }
        // 主对角线胜盘
        if (p == board[0][0] && p == board[1][1] && p == board[2][2]) {
            return true;
        }
        // 次对角线胜盘
        if (p == board[0][2] && p == board[1][1] && p == board[2][0]) {
            return true;
        }
        return false;
    }
};
}

int main(int argc, char** argv) {
    std::vector<std::string> board{"XOX","O O","XOX"};
    std::cout << leetcode_cpp::Solution().validTicTacToe(board) << std::endl;
}