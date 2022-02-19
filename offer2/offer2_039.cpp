#include <vector>
#include <iostream>
#include "limits.h"
#include <deque>
/*
@
LeetCode 剑指offerⅡ
time: 2022-01-10 20:39:13
author: edinw
@
*/

/*
注意：本题与主站 84 题相同： https://leetcode-cn.com/problems/largest-rectangle-in-histogram/

给定非负整数数组 heights ，数组中的数字用来表示柱状图中各个柱子的高度。每个柱子彼此相邻，且宽度为 1 。

求在该柱状图中，能够勾勒出来的矩形的最大面积。
*/

namespace leetcode_cpp {
class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights) {
        int hSize = heights.size();
        std::deque<int> mono_stack;
        mono_stack.push_back(-1);
        int maxArea = 0;
        for (int i = 0; i < hSize; ++i) {
            while (mono_stack.back() != -1 && heights[mono_stack.back()] >= heights[i]) {
                int height = heights.at(mono_stack.back());
                mono_stack.pop_back();
                int width = i - mono_stack.back() - 1;
                maxArea = std::max(maxArea, height * width);
            }
            mono_stack.push_back(i);
        }

        while (mono_stack.back() != -1) {
            int height = heights.at(mono_stack.back());
            mono_stack.pop_back();
            int width = heights.size() - mono_stack.back() - 1;
            maxArea = std::max(maxArea, height * width);
        }
        return maxArea;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> heights{2,1,5,6,2,3};
    std::cout << leetcode_cpp::Solution().largestRectangleArea(heights) << std::endl;
    return 0;
}