#include <bits/stdc++.h>

/*
@
LeetCode
time: 2022-03-20 19:38:23
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int longestPalindromeSubseq(std::string s) {
        int sLen = s.length();
        // dp[i][j]表示字符串s的下标范围[i, j]内的最长回文子序列的长度。
        std::vector<std::vector<int>> dp(sLen, std::vector<int>(sLen));

        for (int i = sLen - 1; i >= 0; --i) {
            dp[i][i] = 1;   // 任何长度为1的子序列都是回文子序列
            char c1 = s[i];
            for (int j = i + 1; j < sLen; ++j) {
                char c2 = s[j];
                if (c1 == c2) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = std::max(dp[i + 1][j], dp[i][j - 1]);    // s[i]和s[j]不可能同时作为同一个回文子序列的首尾，因此dp[i][j] = max(dp[i + 1][j], dp[i][j - 1])。
                }
            }
        }

        return dp[0][sLen - 1];
    }
};
}

int main(int argc, char **argv) {
    std::string s{"bbbab"};

    std::cout << leetcode_cpp::Solution().longestPalindromeSubseq(s) << std::endl;

    return 0;
}
