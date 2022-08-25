#include <vector>
#include <string>
#include "limits.h"
#include <iostream>
/*
@
LeetCode 剑指offerII
time: 2022-03-04 21:32:03
author: edinw
@
*/

/*
**  Given a string s, return the number of palindromic substrings in it.
**
**  A string is a palindrome when it reads the same backward as forward.
**
**  A substring is a contiguous sequence of characters within the string.
*/

namespace leetcode_cpp {
class Solution {
public:
    int countSubstrings(std::string &s) {
        int sLen = s.length();
        int ans = 0;

        auto palindrome = [&] (int lo, int hi) {
            while (lo >= 0 && hi < sLen && s[lo] == s[hi]) {
                --lo;
                ++hi;
                ++ans;
            }
        };
        
        for (int i = 0; i < sLen; ++i) {
            palindrome(i, i);
            palindrome(i, i + 1);
        }

        return ans;
    }
};

class Solution2 {
public:
    int countSubstrings(std::string &s) {
        int sLen = s.length();
        std::vector<std::vector<int>> dp(sLen, std::vector<int>(sLen));
        int ans = 0;

        for (int j=0; j<sLen; ++j) {
            for (int i=0; i<=j; ++i) {
                /*
                // 1. 当只有一个字符时，比如 a 自然是一个回文串。
                // 2. 当有两个字符时，如果是相等的，比如 aa，也是一个回文串。
                // 3. 当有三个及以上字符时，比如 ababa 这个字符记作串 1，把两边的 a 去掉，也就是 bab 记作串 2，可以看出只要串2是一个回文串，那么左右各多了一个 a 的串 1 必定也是回文串。所以当 s[i]==s[j] 时，自然要看 dp[i+1][j-1] 是不是一个回文串。
                */
                if (s[i] == s[j] && (j - i < 2 || dp[i + 1][j - 1])) {
                    dp[i][j] = 1;
                    ++ans;
                }
            }
        }

        return ans;
    }
};
}


int main(int argc, char **argv) {
    std::string s{"aaa"};

    std::cout << leetcode_cpp::Solution2().countSubstrings(s) << std::endl;

    return 0;
}
