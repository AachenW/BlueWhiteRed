#include <vector>
#include <string>
#include <iostream>

/*
@
LeetCode 剑指offerⅡ
time: 2022-01-28 20:14:39
author: edinw
@
*/

/*
**  注意：本题与主站 77 题相同： https://leetcode-cn.com/problems/combinations/
** 
**  There is a robot on an m x n grid. The robot is initially located at the top-left corner (i.e., grid[0][0]). The robot tries to move to the 
**      bottom-right corner (i.e., grid[m - 1][n - 1]). The robot can only move either down or right at any point in time.
**  Given the two integers m and n, return the number of possible unique paths that the robot can take to reach the bottom-right corner.
**  The test cases are generated so that the answer will be less than or equal to 2 * 10^9.
*/

namespace leetcode_cpp {
class Solution {
public:
    int uniquePaths(int m, int n) {
        // initialization
        std::vector<int> dp(n, 1);

        // states transfer
        for (int i = 1; i < m; ++i) {
            for (int j = 1; j < n; ++j) {
                dp[j] += dp[j - 1];
            }
        }
        return dp[n - 1];
    }
};

class Solution2 {
public:
    int uniquePaths(int m, int n) {
        if (m > n) {
            return uniquePaths(n, m);
        }
        long long ans = 1;
        for (int x = n, y = 1; y < m; ++x, ++y) {
            ans = ans * x / y;
        }
        return ans;
    }
};
}

int main(int argc, char **argv) {
    int m = 3, n = 7;
    std::cout << leetcode_cpp::Solution().uniquePaths(m, n) << std::endl;
    return 0;
}