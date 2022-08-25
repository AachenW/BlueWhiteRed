#include <bits/stdc++.h>

/*
@
projetc: leetcode
time: 2022-04-23 15:42:45
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    bool isSubsequence(std::string s, std::string t) {
        int sLen = s.length();
        int tLen = t.length();
        // 如果要想s是t的子序列首先是t的长度要大于s的长度
        if (sLen > tLen) {
            return false;
        }
        // 定义dp数组, dp[i][j]，长度为i，末尾项为s[i - 1]的子字符串，与长度为j，末尾项为t[j - 1]的子字符串，二者的相同子序列长度。
        std::vector<std::vector<int>> dp(sLen + 1, std::vector<int>(tLen + 1));
        // dp数组初始化 dp[i][0] = 0, dp[0][j] = 0
        for (int i = 1; i <= sLen; ++i) {
            for (int j = 1; j <= tLen; ++j) {
                // 找到一个字符，个数+1
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {    // 如果没找到，则需要t往前找
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }

        if (dp[sLen][tLen] == sLen) return true;
        return false;
    }
};
}

int main(int argc, char **argv) {
    std::string s{"axc"};
    std::string t{"ahbgdc"};

    std::cout << leetcode_cpp::Solution().isSubsequence(s, t) << std::endl;

    return 0;
}
