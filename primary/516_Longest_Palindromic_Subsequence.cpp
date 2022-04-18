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
        std::vector<std::vector<int>> dp(sLen, std::vector<int>(sLen));

        for (int i = sLen - 1; i >= 0; --i) {
            dp[i][i] = 1;
            char c1 = s[i];
            for (int j = i + 1; j < sLen; ++j) {
                char c2 = s[j];
                if (c1 == c2) {
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                } else {
                    dp[i][j] = std::max(dp[i + 1][j], dp[i][j - 1]);
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