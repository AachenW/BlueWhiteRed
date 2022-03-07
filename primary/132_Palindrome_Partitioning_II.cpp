#include <string>
#include <vector>
#include <iostream>
#include <limits.h>
/*
@
LeetCode 剑指offerⅡ
time: 2022-01-06 23:01:19
author: edinw
@
*/

/*
**  注意：本题与主站 132 题相同： https://leetcode-cn.com/problems/palindrome-partitioning-ii/
**  
**  Given a string s, partition s such that every substring of the partition is a palindrome.
**  
**  Return the minimum cuts needed for a palindrome partitioning of s.
*/

namespace leetcode_cpp {
class Solution {
public:
    int minCum(std::string s) {
        int sLen = s.length();
        std::vector<std::vector<int>> g(sLen, std::vector<int>(sLen, 1));

        // 预处理，将字符串 s 的每个子串是否为回文串预先计算出来
        for (int i = sLen - 1; i >= 0; --i) {
            for (int j = i + 1; j < sLen; ++j) {
                g[i][j] = s[i] == s[j] && g[i + 1][j - 1];
            }
        }

        // 设 f[i]表示字符串的前缀s[0..i]的最少分割次数
        std::vector<int> dp(sLen, INT_MAX);

        for (int i = 0; i < sLen; ++i) {
            if (g[0][i]) {
                dp[i] = 0;  // s[0,...i]本身就是回文串，所以不需要分割
            } else {
                for (int j = 0; j < i; ++j) {
                    if (g[j + 1][i]) {
                        dp[i] = std::min(dp[j] + 1, dp[i]);
                    }
                }
            }
        }

        return dp[sLen - 1];
    }
};
}

int main(int argc, char **argv) {
    std::string s{"aab"};

    std::cout << leetcode_cpp::Solution().minCum(s) << std::endl;

    return 0;
}