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
注意：本题与主站 132 题相同： https://leetcode-cn.com/problems/palindrome-partitioning-ii/

给定一个字符串 s，请将 s 分割成一些子串，使每个子串都是回文串。
返回符合要求的 最少分割次数 。
*/

namespace leetcode_cpp {
class Solution{
public:
    int minCut(std::string s) {
        int sLength = s.size();
        std::vector<std::vector<int>> g(sLength, std::vector<int>(sLength, true));

        // 预处理，将字符串 s 的每个子串是否为回文串预先计算出来
        for (decltype(sLength)i = sLength - 1; i >= 0; --i) {
            for (decltype(sLength)j = i + 1; j < sLength; ++j) {
                g[i][j] = (s[i] == s[j]) && g[i + 1][j - 1];
            }
        }

        std::vector<int> f(sLength, INT_MAX);   // 设 f[i]表示字符串的前缀s[0..i]的最少分割次数
        
        // states transfer
        for (decltype(sLength)i = 0; i < sLength; ++i) {
            // initialization
            if (g[0][i]) {
                f[i] = 0;   // s[0,...i]本身就是回文串，所以不需要分割
            } else {
                for (decltype(sLength)j = 0; j < i; ++j) {
                    if(g[j + 1][i]) {
                        f[i] = std::min(f[i], f[j] + 1);
                    }
                }
            }
        }
        return f[sLength - 1];
    }
};
}

int main (int argc, char **argv) {
    std::string s{"ab"};
    std::cout << leetcode_cpp::Solution().minCut(s) << std::endl;
    return 0;
}