#include <vector>
#include <iostream>

/*
@
project: leetcode
time: 2022-03-05 15:19:45
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int maximalRectangle(std::vector<std::vector<char>> &matrix) {
        int m = matrix.size();
        if (0 == m) {
            return 0;
        }

        int n = matrix[0].size();
        
        auto largestRectangleArea = [&](std::vector<int> &heights) {
            std::vector<int> mono_stack;
            int maxArea = 0;
            mono_stack.emplace_back(-1);

            for (int i = 0; i < n; ++i) {
                while (-1 != mono_stack.back() && heights[mono_stack.back()] >= heights[i]) {
                    int height = heights[mono_stack.back()];
                    mono_stack.pop_back();
                    int width = i - 1 - mono_stack.back();
                    maxArea = std::max(maxArea, height * width);
                }
                mono_stack.emplace_back(i);
            }

            while (-1 != mono_stack.back()) {
                int height = heights[mono_stack.back()];
                mono_stack.pop_back();
                int width = n - mono_stack.back() - 1;
                maxArea = std::max(maxArea, height * width);
            }

            return maxArea;
        };
        
        std::vector<int> height(n, 0);
        int maxArea = 0;
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if ('0' == matrix[i][j]) {
                    height[j] = 0;
                } else {
                    height[j] += matrix[i][j] - '0';
                }
            }

            maxArea = std::max(maxArea, largestRectangleArea(height));
        }

        return maxArea;
    }

};

}

int main(int argc,char **argv) {
    std::vector<std::vector<char>> matrix {{'1', '0', '1', '0', '0'}, {'1', '0', '1', '1', '1'}, {'1', '1', '1', '1', '1'}, {'1', '0', '0', '1', '0'}};

    std::cout << leetcode_cpp::Solution().maximalRectangle(matrix) << std::endl;

    return 0;

}
