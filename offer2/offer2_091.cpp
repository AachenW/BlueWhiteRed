#include <string>
#include <vector>
#include <iostream>
/*
@
LeetCode 剑指offerⅡ
time: 2022-01-05 20:34:35
author: edinw
@
*/


/*
注意：本题与主站 256 题相同：https://leetcode-cn.com/problems/paint-house/

假如有一排房子，共 n 个，每个房子可以被粉刷成红色、蓝色或者绿色这三种颜色中的一种，你需要粉刷所有的房子并且使其相邻的两个房子颜色不能相同。

当然，因为市场上不同颜色油漆的价格不同，所以房子粉刷成不同颜色的花费成本也是不同的。每个房子粉刷成不同颜色的花费是以一个 n x 3 的正整数矩阵 costs 来表示的。

例如，costs[0][0] 表示第 0 号房子粉刷成红色的成本花费；costs[1][2] 表示第 1 号房子粉刷成绿色的花费，以此类推。

请计算出粉刷完所有房子最少的花费成本。
*/


namespace leetcode_cpp {
class Solution {
public:
    int minCost(std::vector<std::vector<int>> &costs) {
        int n = costs.size();
        if (0 == n) {
            return 0;
        }

        // initialization
        int print_red = costs[0][0];
        int print_blue = costs[0][1];
        int print_green = costs[0][2];
        if (1 == n) {
            return std::min(std::min(print_red, print_blue), print_green);
        }

        // state transfer function
        for (int i = 1; i < n; ++i) {
            int temp_red = std::min(print_blue, print_green) + costs[i][0];
            int temp_blue = std::min(print_red, print_green) + costs[i][1];
            int temp_green = std::min(print_red, print_blue) + costs[i][2];
            print_red = temp_red;
            print_blue = temp_blue;
            print_green = temp_green;
        }
        return std::min(std::min(print_red, print_blue), print_green);
    }
};
}

int main(int argc, char **argv) {
    //[[3,5,3],[6,17,6],[7,13,18],[9,10,18]]
    std::vector<std::vector<int>> costs {{3,5,3},{6,17,6},{7,13,18}, {9,10,18}};
    std::cout << leetcode_cpp::Solution().minCost(costs) << std::endl;
    return 0;
}