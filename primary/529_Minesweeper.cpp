#include <vector>
#include <iostream>
#include <functional>
/*
@
project: leetcode
time: 2022-03-05 10:24:20
author: edinw
@
*/

/*
**  让我们一起来玩扫雷游戏！
**
**  给你一个大小为 m x n 二维字符矩阵 board ，表示扫雷游戏的盘面，其中：
**      'M' 代表一个 未挖出的 地雷，
**      'E' 代表一个 未挖出的 空方块，
**      'B' 代表没有相邻（上，下，左，右，和所有4个对角线）地雷的 已挖出的 空白方块，
**      数字（'1' 到 '8'）表示有多少地雷与这块 已挖出的 方块相邻，
**      'X' 则表示一个 已挖出的 地雷。
**  给你一个整数数组 click ，其中 click = [clickr, clickc] 表示在所有 未挖出的 方块（'M' 或者 'E'）中的下一个点击位置（clickr 是行下标，clickc 是列下标）。
**
**  根据以下规则，返回相应位置被点击后对应的盘面：
**      如果一个地雷（'M'）被挖出，游戏就结束了- 把它改为 'X' 。
**      如果一个 没有相邻地雷 的空方块（'E'）被挖出，修改它为（'B'），并且所有和其相邻的 未挖出 方块都应该被递归地揭露。
**      如果一个 至少与一个地雷相邻 的空方块（'E'）被挖出，修改它为数字（'1' 到 '8' ），表示相邻地雷的数量。
**      如果在此次点击中，若无更多方块可被揭露，则返回盘面。
*/

namespace leetcode_cpp {
class Solution {
    static constexpr int dirs[8][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {1, 1}, {-1, 1}, {1, -1}, {-1, -1}};
public:
    std::vector<std::vector<char>> updateBoard(std::vector<std::vector<char>> &board, std::vector<int> &click) {
        if (0 == board.size() || 0 == board[0].size()) {
            return {};
        }
        int rows = board.size(), cols = board[0].size();
        
        std::function<void(int, int)> backtrack = [&](int x, int y) {
            int cnt = 0;
            for (const auto &dir: dirs) {
                int newX = x + dir[0];
                int newY = y + dir[1];
                if (newX >= 0 && newX < rows && newY >= 0 && newY < cols) {
                    cnt += board[newX][newY] == 'M';
                }
            }

            if (cnt > 0) {
                // 规则3
                board[x][y] = cnt + '0';
            } else {
                // 规则2
                board[x][y] = 'B';
                for (const auto &dir: dirs) {
                    int newX = x + dir[0];
                    int newY = y + dir[1];
                    if (newX >= 0 && newX < rows && newY >= 0 && newY < cols && 'E' == board[newX][newY]) {
                        backtrack(newX, newY);
                    }
                }
            }
        };
        
        int x = click[0], y = click[1];
        if ('M' == board[x][y]) {
            board[x][y] = 'X';
        } else {
            backtrack(x, y);
        }

        return board;
    }
};
}

int main(int argc, char **argv) {
    std::vector<std::vector<char>> board{{'E', 'E', 'E', 'E', 'E'}, {'E', 'E', 'M', 'E', 'E'}, {'E', 'E', 'E', 'E', 'E'}, {'E', 'E', 'E', 'E', 'E'}};
    std::vector<int> click{3, 0};

    auto matrix = leetcode_cpp::Solution().updateBoard(board, click);
    for (const auto &rows: matrix) {
        for (const char num: rows) {
            std::cout << num << ",";
        }
        std::cout << std::endl;
    }

    return 0;
}
