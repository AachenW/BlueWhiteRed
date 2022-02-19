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
        std::vector<int> mono_stack;
        mono_stack.emplace_back(-1);
        int maxArea = 0;
        for (int i = 0; i < hSize; ++i) {
            while (-1 != mono_stack.back() && heights[mono_stack.back()] >= heights[i]) {
                int height = heights[mono_stack.back()];
                mono_stack.pop_back();
                int width = i - mono_stack.back() - 1;
                maxArea = std::max(maxArea, width * height);
            }
            mono_stack.emplace_back(i);
        }

        while (-1 != mono_stack.back()) {
            int height = heights[mono_stack.back()];
            mono_stack.pop_back();
            int width = heights.size() - mono_stack.back() - 1;
            maxArea = std::max(maxArea, height * width);
        }
        return maxArea;
    } 
};
}

int main(int argc, char **argv) {
    std::vector<int> heights {2, 1, 5, 6, 2, 3};
    std::cout << leetcode_cpp::Solution().largestRectangleArea(heights) << std::endl;
    return 0;
}