#include <string>
#include <vector>
#include <iostream>
/*
@
LeetCode 剑指offerⅡ
time: 2022-01-07 21:24:42
author: edinw
@
*/

/*
注意：本题与主站 1143 题相同： https://leetcode-cn.com/problems/longest-common-subsequence/

给定两个字符串 text1 和 text2，返回这两个字符串的最长 公共子序列 的长度。如果不存在 公共子序列 ，返回 0 。

一个字符串的 子序列 是指这样一个新的字符串：它是由原字符串在不改变字符的相对顺序的情况下删除某些字符（也可以不删除任何字符）后组成的新字符串。
例如，"ace" 是 "abcde" 的子序列，但 "aec" 不是 "abcde" 的子序列。
*/

namespace leetcode_cpp {
class Solution {
public:
    int longestCommonSubsequence(std::string text1, std::string text2) {
        int m = text1.length(), n = text2.length();

        // initialization
        std::vector<std::vector<int>> dp(m + 1, std::vector<int>(n + 1, 0));
        
        // states transfer
        for (int i = 1; i <= m; ++i) {
            char ch1 = text1.at(i - 1);
            for (int j = 1; j <= n; ++j) {
                char ch2 = text2.at(j - 1);
                if (ch1 == ch2) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        return dp[m][n];
    }
};
}

int main(int argc, char **argv) {
    std::string text1 {"abc"}, text2 {"abc"};
    std::cout << leetcode_cpp::Solution().longestCommonSubsequence(text1, text2) << std::endl;
    return 0;
}