#include <iostream>
#include <vector>
#include <deque>
/*
@
LeetCode HOT 100
time: 2022-02-11 23:08:58
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int trap(std::vector<int> &height) {
        int n = height.size();
        if (0 == n) {
            return 0;
        }
        std::vector<int> leftMax(n);
        leftMax[0] = height[0];
        for (int i = 1; i < n; ++i) {
            leftMax[i] = std::max(leftMax[i - 1], height[i]);
        }

        std::vector<int> rightMax(n);
        rightMax[n - 1] = height[n - 1];
        for (int j = n - 2; j >= 0; --j) {
            rightMax[j] = std::max(rightMax[j + 1], height[j]);
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            ans += std::min(leftMax[i], rightMax[i]) - height[i];
        }

        return ans;
    }
};

class Solution2 {
public:
    int trap(std::vector<int> &heights) {
        // 单调栈存储的是下标，满足从栈底到栈顶的下标对应的数组 height 中的元素递减
        std::deque<int> mono_stack;
        int nSize = heights.size();
        int ans = 0;
        for (int i = 0; i < nSize; ++i) {
            while (!mono_stack.empty() && heights[i] > heights[mono_stack.back()]) {
                // 记栈顶元素为 top，top 的下面一个元素是 left
                int top = mono_stack.back();
                // 为了得到 left，需要将 top 出栈
                mono_stack.pop_back();
                if (mono_stack.empty()) {
                    break;
                }
                int left = mono_stack.back();
                // 该区域的宽度是 i−left−1
                int width = i - left - 1;
                // 高度是 min(height[left],height[i])−height[top]
                int height = std::min(heights[left], heights[i]) - heights[top];
                ans += height * width;
            }   // left 变成新的 top，重复上述操作，直到栈变为空，或者栈顶下标对应的 height 中的元素大于或等于 height[i]
            mono_stack.emplace_back(i);
        }

        return ans;
    }
};

class Solution3 {
public: 
    int trap(std::vector<int> &height) {
        int nSize = height.size();
        int left = 0, right = nSize - 1;
        int leftMax = 0, rightMax = 0;
        int ans = 0;
        while (left < right) {
            // 使用 height[left] 和 height[right] 的值更新 leftMax 和 rightMax 的值
            leftMax = std::max(leftMax, height[left]);
            rightMax = std::max(rightMax, height[right]);
            if (height[left] < height[right]) {     // 有leftMax < rightMax
                ans += leftMax - height[left];      // 下标 left 处能接的雨水量等于 leftMax−height[left]，将下标 left 处能接的雨水量加到能接的雨水总量
                ++left;                             // left向右移动一位
            } else {                                // 有leftMax >= rightMax
                ans += rightMax - height[right];    // 下标 right 处能接的雨水量等于 rightMax−height[right]，将下标 right 处能接的雨水量加到能接的雨水总量
                --right;                            // right向左移动一位
            }
        }

        return ans;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums{4, 2, 0, 3, 2, 5};
    std::cout << leetcode_cpp::Solution3().trap(nums) << std::endl;
    return 0;
}