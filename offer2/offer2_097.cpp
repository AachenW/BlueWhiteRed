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
    int numDistinct(std::string &s, std::string &t) {
        int sLength = s.length(), tLength = t.length();
        if (sLength < tLength) {
            return 0;
        }
        // dp[i][j]表示在s[i:]的子序列中t[j:]出现的个数
        auto dp = std::vector<std::vector<unsigned long long>> (sLength + 1, std::vector<unsigned long long>(tLength + 1, 0));
        
        // 当j=n时，t[j:]为空字符串，由于空字符串是任何字符串的子序列，因此对任意0≤i≤m，有dp[i][n]=1;
        // 当i=m且j<n时, s[i:]为空字符串，t[j:] 为非空字符串，由于非空字符串不是空字符串的子序列，因此对任意0≤j<n，有dp[m][j]=0。
        // initialization
        for (int i = 0; i <= sLength; ++i) {
            dp[i][tLength] = 1;
        }

        // states transfer 
        for (int i = sLength - 1; i >= 0; --i) {
            const char sChar = s.at(i);
            for (int j = tLength - 1; j >= 0; --j) {
                const char tChar = t.at(j);
                if (sChar == tChar) {
                    // 如果匹配，那么 dp[i][j] 其中一部分数量就是 dp[i+1][j+1]
                    // 如果选择不匹配（这样可以让前面的字符跟t[j]匹配，毕竟t 短的,s 长) dp[i][j] 另外一部分就是 dp[i+1][j]
                    dp[i][j] = dp[i + 1][j + 1] + dp[i + 1][j];
                } else {
                    // not matched
                    dp[i][j] = dp[i + 1][j];
                }
            }
        }
        return dp[0][0];
    }
};

class Solution2 {
public:
    int numDistinct(std::string &s, std::string &t) {
        int sLength = s.length(), tLength = t.length();
        if (sLength < tLength) {
            return 0;
        }
        
        // dp is initially meant to dp[sLength]. 
        auto dp = std::vector<int>(tLength + 1);

        // initialize dp[sLength][tLength] = 1
        dp[tLength] = 1;
        for (int i = sLength - 1; i >= 0; --i) {
            const char sChar = s.at(i);
            for (int j = 0; j < tLength; ++j) {
                const char tChar = t.at(j);
                if (sChar == tChar) {
                    // 此处的dp[j]相当于二维dp数组中的dp[i][j], dp[j + 1]相当于二维dp数组中的dp[i][j + 1].
                    dp[j] += dp[j + 1];
                }
            }
        }
        return dp[0];
    }
};
}

int main(int argc, char **argv) {
    std::string s {"rabbbit"}, t{"rabbit"};
    std::cout << leetcode_cpp::Solution2().numDistinct(s, t) << std::endl;
    return 0;
}