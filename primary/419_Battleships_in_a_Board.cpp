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
project: leetcode
time: 2021-12-18 22:17:40
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int countBattleships(std::vector<std::vector<char>> &board) {
        int row = board.size();
        int col = board[0].size();
        int ans = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if ('X' == board[i][j]) {
                    if (i > 0 && 'X' == board[i - 1][j]){
                        continue;
                    }
                    if (j > 0 && 'X' == board[i][j - 1]) {
                        continue;
                    }
                    ++ans;
                }
            }
        }
        return ans;
    }
};
}

int main(int argc, char **argv) {
    std::vector<std::vector<char>> board {{'X', '.', '.', 'X'}, {'.', '.', '.', 'X'}, {'.', '.', '.', 'X'}};
    std::cout << leetcode_cpp::Solution().countBattleships(board) << std::endl;
    return 0;
}