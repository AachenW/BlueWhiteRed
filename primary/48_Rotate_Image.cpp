#include <iostream>
#include <vector>

/*
@
LeetCode HOT 100
time: 2022-02-05 22:57:24
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    void rotate(std::vector<std::vector<int>> &matrix) {
        int sides = matrix.size();
        auto matrixNew = matrix;
        for (int i = 0; i < sides; ++i) {
            for (int j = 0; j < sides; ++j) {
                matrixNew[j][sides - i - 1] = matrix[i][j];
            }
        }
        matrix = matrixNew;
    }
};

class Solution2 {
public:
    void rotate(std::vector<std::vector<int>> &matrix) {
        int n = matrix.size();
        for (int i = 0; i < n / 2; ++i) {
            for (int j = 0; j < (n + 1) / 2; ++j) {
                int temp = matrix[i][j];
                matrix[i][j] = matrix[n - j - 1][i];
                matrix[n - j - 1][i] = matrix[n - i - 1][n - j - 1];
                matrix[n - i - 1][n - j - 1] = matrix[j][n - i - 1];
                matrix[j][n - i - 1] = temp;
            }
        }
    }
};

class Solution3 {
public:
    void rotate(std::vector<std::vector<int>> &matrix) {
        int n = matrix.size();
        // 水平翻转
        for (int i = 0; i < n / 2; ++i) {
            for (int j = 0; j < n; ++j ) {
                std::swap(matrix[i][j], matrix[n - i - 1][j]);
            }
        }

        // 主对角线翻转，结果是顺时针旋转90°
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                std::swap(matrix[i][j], matrix[j][i]);
            }
        }
        // // 副对角线翻转，结果是逆时针旋转90°
        // for (int i = 0; i < n; ++i) {
        //     for (int j = 0; j < n - i; ++j) {
        //         std::swap(matrix[i][j], matrix[n - j - 1][n - i - 1]);
        //     }
        // }
    }
};
}

int main(int argc, char **argv) {
    std::vector<std::vector<int>> matrix{{1, 2, 3},
                                         {4, 5, 6},
                                         {7, 8, 9}};
    leetcode_cpp::Solution3().rotate(matrix);
    for (const auto &nums: matrix) {
        for (const auto &num: nums) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}