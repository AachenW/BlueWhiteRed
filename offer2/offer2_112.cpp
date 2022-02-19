#include <vector>
#include <iostream>
#include <deque>
#include "limits.h"
#include <unordered_set>
#include <queue>
/*
@
LeetCode 剑指offerⅡ
time: 2022-01-17 21:40:16
author: edinw
@
*/

/*
** 注意：本题与主站 329 题相同： https://leetcode-cn.com/problems/longest-increasing-path-in-a-matrix/
**
** 给定一个 m x n 整数矩阵 matrix ，找出其中 最长递增路径 的长度。
** 对于每个单元格，你可以往上，下，左，右四个方向移动。 不能 在 对角线 方向上移动或移动到 边界外（即不允许环绕）。
*/


namespace leetcode_cpp {
class Solution {
    static constexpr int dirctions[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    int rows, cols;
public:
    int longestIncreasingPath(std::vector<std::vector<int>>& matrix) {
        if (0 == matrix.size() || 0 == matrix.at(0).size()) {
            return 0;
        }
        rows = matrix.size();
        cols = matrix.at(0).size();
        // 用矩阵 memo 作为缓存矩阵，已经计算过的单元格的结果存储到缓存矩阵中。
        auto memo = std::vector<std::vector<int>>(rows, std::vector<int>(cols, 0));
        int ans = 0;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                ans = std::max(ans, backtrack(matrix, memo, i, j));
            }
        }
        return ans;
    }

private:
    int backtrack(std::vector<std::vector<int>> &matrix, std::vector<std::vector<int>> &memo, int row, int col) {
        // 该单元格的结果已经计算过，则直接从缓存中读取结果
        if (memo[row][col] != 0) {
            return memo[row][col];
        }
        // 说明该单元格的结果尚未被计算过，则进行搜索，并将计算得到的结果存入缓存中。
        ++memo[row][col];
        for (int i = 0; i < 4; ++i) {
            int newRow = row + dirctions[i][0];
            int newCol = col + dirctions[i][1];
            if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && matrix[newRow][newCol] > matrix[row][col]) {
                memo[row][col] = std::max(backtrack(matrix, memo, newRow, newCol) + 1, memo[row][col]);
            }
        }
        return memo[row][col];
    }
};

class Solution2 {
    static constexpr int dirctions[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
    int rows, cols;
public:
    int longestIncreasingPath(std::vector<std::vector<int>>& matrix) {
        if (0 == matrix.size() || 0 == matrix.at(0).size()) {
            return 0;
        }

        rows = matrix.size();
        cols = matrix.at(0).size();
        auto outdegrees = std::vector<std::vector<int>>(rows, std::vector<int>(cols));

        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                for (int k = 0; k < 4; ++k) {
                    int newRow = i + dirctions[k][0];
                    int newCol = j + dirctions[k][1];
                    if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && matrix[newRow][newCol] > matrix[i][j]) {
                        ++outdegrees[i][j];
                    }
                }
            }
        }

        std::deque<std::pair<int, int>> queue;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (0 == outdegrees[i][j]) {
                    queue.emplace_back(std::make_pair(i, j));
                }
            }
        }

        int ans = 0;
        while (!queue.empty()) {
            ++ans;
            int size = queue.size();
            for (int i = 0; i < size; ++i) {
                auto element = queue.front();
                queue.pop_front();
                for (int k = 0; k < 4; ++k) {
                    int newRow = element.first + dirctions[k][0];
                    int newCol = element.second + dirctions[k][1];
                    if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < cols && matrix[newRow][newCol] < matrix[element.first][element.second]) {
                        --outdegrees[newRow][newCol];
                        if (0 == outdegrees[newRow][newCol]) {
                            queue.emplace_back(std::make_pair(newRow, newCol));
                        }
                    }
                }
            }
        }

        return ans;
    }
};
}

constexpr int leetcode_cpp::Solution::dirctions[4][2];
constexpr int leetcode_cpp::Solution2::dirctions[4][2];

int main(int argc, char **argv) {
    std::vector<std::vector<int>> matrix {{3, 4, 5}, {3, 2, 6}, {2, 2, 1}};
    std::cout << leetcode_cpp::Solution().longestIncreasingPath(matrix) << std::endl;
    return 0;
}