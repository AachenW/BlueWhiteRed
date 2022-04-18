#include <string>
#include <unordered_map>
#include <limits.h>
#include <iostream>
#include <vector>
/*
@
projetc: leetcode
time: 2022-02-07 23:39:18
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int largestRectangleArea(std::vector<int> &heights) {
        int hSize = heights.size();
        std::vector<int> mono_stack;    // 栈内存储的为递增序列
        // 哨兵-1的作用是将栈内保存递减序列的特殊情况一并考虑，使代码不需要再进行判断特殊情况
        mono_stack.emplace_back(-1);
        int maxArea = 0;
        for (int i = 0; i < hSize; ++i) {
            while (-1 != mono_stack.back() && heights[mono_stack.back()] >= heights[i]) {
                int height = heights[mono_stack.back()]; mono_stack.pop_back();
                int width = i - mono_stack.back() - 1;
                maxArea = std::max(maxArea, width * height);
            }
            mono_stack.emplace_back(i);
        }

        while (-1 != mono_stack.back()) {
            int height = heights[mono_stack.back()]; mono_stack.pop_back();
            int width = heights.size() - mono_stack.back() - 1;
            maxArea = std::max(maxArea, height * width);
        }
        return maxArea;
    } 
};

class Solution2 {
public:
    int largestRectangleArea(std::vector<int>& heights) {
        int hSize = heights.size();
        std::vector<int> mono_stack;
        int ans = 0;

        for (int i = 0; i < hSize; ++i) {
            while (!mono_stack.empty() && heights[mono_stack.back()] > heights[i]) {
                int top = mono_stack.back(); mono_stack.pop_back();
                int width = i;
                if (!mono_stack.empty()) {
                    int left = mono_stack.back();
                    width = i - left - 1;
                }
                int area = width * heights[top];
                ans = std::max(ans, area);
            }
            mono_stack.emplace_back(i);
        }

        while (!mono_stack.empty()) {
            int height = heights[mono_stack.back()]; mono_stack.pop_back();
            int width = hSize;
            if (!mono_stack.empty()) {
                width = hSize - mono_stack.back() - 1;
            }
            int area = width * height;
            ans = std::max(ans, area);
        }

        return ans;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> heights {2, 1, 5, 6, 2, 3};
    std::cout << leetcode_cpp::Solution().largestRectangleArea(heights) << std::endl;
    return 0;
}
