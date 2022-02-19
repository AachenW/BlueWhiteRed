#include <vector>
#include <iostream>
#include <algorithm>
#include "limits.h"
#include "../lib/BinaryTree.h"

/*
@
LeetCode 剑指offer
time: 2022-02-18 23:25:08
author: edinw
@
*/

/*
**  注意：本题与主站 54 题相同：https://leetcode-cn.com/problems/spiral-matrix/
** 
**  Given an m x n matrix, return all elements of the matrix in spiral order.
*/

namespace leetcode_cpp {
class Solution {
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>> &matrix) {
        std::vector<int> order;
        if (matrix.empty()) {
            return order;
        }
        int rows = matrix.size(), cols = matrix[0].size();
        int left = 0, right = cols - 1, top = 0, bottom = rows - 1;             // 赋值上下左右边界
        while (true) {
            for (int i = left; i <= right; ++i) {
                order.emplace_back(matrix[top][i]);         // 向右移动直到最右
            }
            if (++top > bottom) {
                break;                                      // 重新设定上边界，若上边界大于下边界，则遍历遍历完成，下同
            }
            for (int i = top; i <= bottom; ++i) {
                order.emplace_back(matrix[i][right]);       // 向下
            }
            if (--right < left) {
                break;                                      // 重新设定右边界
            }
            for (int i = right; i >= left; --i) {
                order.emplace_back(matrix[bottom][i]);      // 向右
            }
            if (--bottom < top) {                           // 重新设定下边界
                break;
            }
            for (int i = bottom; i >= top; --i) {
                order.emplace_back(matrix[i][left]);        // 向上
            }
            if (++left > right) {
                break;                                      // 重新设定上边界
            }
        }

        return order;
    }
};
}

int main(int argc, char **argv) {
    std::vector<std::vector<int>> matrix {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    auto ans = leetcode_cpp::Solution().spiralOrder(matrix);
    for (const auto &num: ans) {
        std::cout << num << ", ";
    }
    std::cout << std::endl;
    return 0;
}