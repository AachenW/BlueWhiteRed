#include <string>
#include <iostream>
#include <vector>

/*
@
LeetCode 剑指offerⅡ
time: 2022-01-02 20:00:47
author: edinw
@
*/

/*
注意：本题与主站 647 题相同：https://leetcode-cn.com/problems/palindromic-substrings/ 
给定一个字符串 s ，请计算这个字符串中有多少个回文子字符串。

具有不同开始位置或结束位置的子串，即使是由相同的字符组成，也会被视作不同的子串。
*/

namespace leetcode_cpp {
class Solution{
public:
    int countSubstring(std::string s) {
        n = s.size();
        ans = 0;

        for (int i = 0; i < n; ++i) {
            // 回文串中心为奇数
            Palindrome(s, i, i);
            // 回文串中心为偶数
            Palindrome(s, i, i + 1);
        }
        return ans;
    }
private:
    void Palindrome(std::string &s, int lo, int hi) {
        while(lo >= 0 && hi < n && s[lo] == s[hi]) {
            --lo;
            ++hi;
            ++ans;
        }
    }
private:
    int n;
    int ans;
};

class Solution2{
public:
    int countSubstring(std::string s){
        int n = s.size();
        if (1 == n) {
            return 1;
        }
        int ans = 0;

        // state
        std::vector<std::vector<bool>> dp(n, std::vector<bool>(n, false));

        // initialize
        for (int i = 0; i < n; ++i) {
            dp[i][i] = true;
            ++ans;
        }
        for (int i = 0, j = 1; j < n; ++i, ++j) {
            dp[i][j] = s[i] == s[j];
            if (dp[i][j]) {
                ++ans;
            }
        }

        // function
        for (int l = 3; l <= n; ++l) {  // 遍历所有长度大于2的子串
            for (int i = 0, j = i + l -1; j < n; ++i, ++j) {
                dp[i][j] = s[i] == s[j] && dp[i + 1][j - 1];
                if (dp[i][j]) {
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
    std::cout << leetcode_cpp::Solution2().countSubstring(s) << std::endl;
    return 0;
}
