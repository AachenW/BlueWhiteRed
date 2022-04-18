#include <vector>
#include <string>
#include <iostream>

/*
@
LeetCode 剑指offerⅡ
time: 2022-01-10 22:33:27
author: edinw
@
*/

/*
注意：本题与主站 120 题相同： https://leetcode-cn.com/problems/triangle/

给定一个三角形 triangle ，找出自顶向下的最小路径和。

每一步只能移动到下一行中相邻的结点上。相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1 的两个结点。也就是说，如果正位于当前行的下标 i ，那么下一步可以移动到下一行的下标 i 或 i + 1 。
*/

namespace leetcode_cpp {
class Solution1 {
public:
    int minimumTotal (std::vector<std::vector<int>> &triangle) {
        int n = triangle.size();
        auto dp = std::vector<std::vector<int>>(n, std::vector<int>(n, 0));
        dp[0][0] = triangle[0][0];
        for (int i = 1; i < n; ++i) {
            dp[i][0] += triangle[i][0];
            for (int j = 1; j < i; ++j) {
                dp[i][j] = std::min(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j];
            }
            dp[i][i] = dp[i - 1][i - 1] + triangle[i][i];              
        }
        return *std::min_element(dp[n - 1].begin(), dp[n - 1].end());
    }
};

class Solution2 {
public:
    int minimumTotal (std::vector<std::vector<int>> &triangle) {
        int rows = triangle.size(), cols = triangle[rows - 1].size();
        if (0 == rows || 0 == cols) {
            return 0;
        }
        auto dp = std::vector<int>(cols, 0);
        dp[0] = triangle[0][0];
        if (1 == rows) {
            return dp[0];
        }

        // dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j]) + triangle[i][j]
        for (int i = 1; i < rows; ++i) {
            for (int j = 1; j < i; ++j) {
                dp[j] = std::min(dp[j - 1], dp[j]) + triangle[i][j];
            }
            
        }
        return dp[cols - 1];
    }
};
}

int main(int argc, char **argv) {
    std::vector<std::vector<int>> triangle {{2}, {3, 4}, {6, 5, 7}, {4, 1, 8, 3}};
    std::cout << leetcode_cpp::Solution1().minimumTotal(triangle) << std::endl;
    return 0;
}