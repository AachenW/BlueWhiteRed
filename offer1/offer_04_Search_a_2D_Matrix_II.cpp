#include <vector>
#include <iostream>
#include <algorithm>

/*
@
LeetCode 剑指offer
time: 2022-02-01 15:09:31
author: edinw
@
*/

/*
**  注意：本题与主站 77 题相同： https://leetcode-cn.com/problems/combinations/
** 
**  Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:
**      Integers in each row are sorted in ascending from left to right.
**      Integers in each column are sorted in ascending from top to bottom.
*/

namespace leetcode_cpp {
class Solution {
public:
    bool findNumberIn2DArray(std::vector<std::vector<int>>& matrix, int target) {
        for (const auto &row: matrix) {
            auto it = std::lower_bound(row.begin(), row.end(), target);
            if (it != row.end() && *it == target) {
                return true;
            }
        }
        return false;
    }
};

class Solution2 {
public:
    bool findNumberIn2DArray(std::vector<std::vector<int>>& matrix, int target) {
        int rows = matrix.size();
        if (0 == rows) {
            return false;
        }
        int cols = matrix[0].size();
        int x = rows - 1, y = 0;
        while (x >= 0 && y < cols) {
            if (matrix[x][y] == target) {
                return true;
            } else if (matrix[x][y] > target) {
                --x;
            } else {
                ++y;
            }
        }
        return false;
    }
};
}

int main(int argc, char **argv) {
    std::vector<std::vector<int>> nums{{1,   4,  7, 11, 15},
                                       {2,   5,  8, 12, 19},
                                       {3,   6,  9, 16, 22},
                                       {10, 13, 14, 17, 24},
                                       {18, 21, 23, 26, 30}};
    std::vector<std::vector<int>> nums2;
    int target = 5;
    std::cout << std::boolalpha << leetcode_cpp::Solution2().findNumberIn2DArray(nums2, 0) << std::endl;
    return 0;
}