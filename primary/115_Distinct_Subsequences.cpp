#include <vector>
#include <string>
#include <iostream>

/*
@
LeetCode 剑指offerⅡ
time: 2022-01-09 20:01:53
author: edinw
@
*/

/*
注意：本题与主站 97 题相同： https://leetcode-cn.com/problems/interleaving-string/

给定一个字符串 s 和一个字符串 t ，计算在 s 的子序列中 t 出现的个数。
字符串的一个 子序列 是指，通过删除一些（也可以不删除）字符且不干扰剩余字符相对位置所组成的新字符串。（例如，"ACE" 是 "ABCDE" 的一个子序列，而 "AEC" 不是）

题目数据保证答案符合 32 位带符号整数范围。
*/

namespace leetcode_cpp {
class Solution {
public:
    int numDistinct(std::string s, std::string t) {
        int sLen = s.length(), tLen = t.length();
        if (s.size() < t.size()) {
            return 0;
        }
        // 设f(i, j)表示字符串s下标从0到i的子字符串s[0]~s[i]中等于字符串t下标从0到j的子字符串 t[0] ~ t[j] 的子序列个数
        std::vector<std::vector<unsigned int>> dp(sLen + 1, std::vector<unsigned int>(tLen + 1));
        dp[0][0] = 1;
        
        for (int i = 0; i < sLen; ++i) {
            dp[i + 1][0] = 1;   //初始化，因为t为0时，不论s为多长为什么，都能匹配上。
            for (int j = 0; j <= i && j < tLen; ++j) {
                dp[i + 1][j + 1] = (s[i] == t[j]) ? dp[i][j] + dp[i][j + 1] : dp[i][j + 1];
            }
        }

        return dp[sLen][tLen];
    }
};
}