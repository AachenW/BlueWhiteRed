#include <vector>
#include <iostream>
#include "limits.h"
#include <deque>
/*
@
LeetCode 剑指offerⅡ
time: 2022-01-11 19:28:00
author: edinw
@
*/

/*
注意：本题与主站 85 题相同（输入参数格式不同）： https://leetcode-cn.com/problems/maximal-rectangle/

给定一个由 0 和 1 组成的矩阵 matrix ，找出只包含 1 的最大矩形，并返回其面积。

注意：此题 matrix 输入格式为一维 01 字符串数组。
*/

namespace leetcode_cpp {
class Solution {
public:
    int maximalRectangle(std::vector<std::string> &matrix) {
        int m = matrix.size();
        if (0 == m) {
            return 0;
        }
        int n = matrix[0].size();
        auto left = std::vector<std::vector<int>>(m, std::vector<int>(n, 0));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if ('1' == matrix[i][j]) {
                    left[i][j] = (j == 0 ? 0 : left[i][j - 1]) + 1;
                }
            }
        }

        int ret = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if ('0' == matrix[i][j]) {
                    continue;
                }
                int width = left[i][j];
                int area = width;
                for (int k = i - 1; k >= 0; k--) {
                    width = std::min(width, left[k][j]);
                    area = std::max(area, (i - k + 1) * width);
                }
                ret = std::max(ret, area);
            }
        }
        return ret;
    }
};

class Solution2{
public:
    int maximalRectangle(std::vector<std::string> &matrix) {
        int m = matrix.size();
        if (0 == m) {
            return 0;
        }
        int n = matrix[0].size();
        std::vector<int> heights(n, 0);
        int maxArea = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {       //把矩阵的矩阵形式，构造成同上一题的“直方图最大矩形”
                // 也就是每次看一行数据，这一行到第一行之间的矩形看做直方图。下一行“1”能和上一行接上就累加，数值就代表矩形高度, 不然下一行的高度就归零。
                if (matrix[i][j] == '0') {
                    heights[j] = 0;
                } else {
                    heights[j] += matrix[i][j] - '0';
                }
            }
            // 遍历每一行到最开始行之间的矩阵所形成的最大面积
            maxArea = std::max(maxArea, largestRectangleArea(heights));
        }
        return maxArea;
    }

private:
    // offer2_039.cpp 
    int largestRectangleArea(std::vector<int> &heights) {
        int hSize = heights.size();
        if (0 == hSize) {
            return 0;
        }

        std::vector<int> mono_stack;
        mono_stack.emplace_back(-1);
        int ans = 0;
        for (int i = 0; i < hSize; ++i) {
            while (mono_stack.back() != -1 && heights.at(mono_stack.back()) >= heights.at(i)) {
                int height = heights.at(mono_stack.back());
                mono_stack.pop_back();
                int width = i - 1 - mono_stack.back();
                ans = std::max(ans, width * height);
            }
            mono_stack.push_back(i);
        }
        // heights.at(mono_stack.back()) >= 0,则可以将栈中剩余柱子出栈并计算面积
        while (mono_stack.back() != -1 ) {
            int height = heights.at(mono_stack.back());
            mono_stack.pop_back();
            int width = heights.size() - mono_stack.back() - 1;
            ans = std::max(ans, width * height);
        }
        return ans;
    }
};
}

int main(int argc, char **argv) {
    std::vector<std::string> matrix {"10100","10111","11111","10010"};
    std::cout << leetcode_cpp::Solution2().maximalRectangle(matrix) << std::endl;
    return 0;
}