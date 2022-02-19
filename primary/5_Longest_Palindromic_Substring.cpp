#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <ctime>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cstdlib>
#include <numeric>

/*
@
LeetCode 精选 TOP 面试题
time: 2021-12-10 21:46:06
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    std::string longestPalindrome(std::string s) {
        int sLength = s.size();
        // 当字符串长度为1时，显然为回文串
        if (sLength < 2) {
            return s;
        }

        int maxLen = 1;
        int begin = 0;
        // dp[i][j] 表示s[i..j]是否是回文串
        std::vector<std::vector<int>> dp(sLength, std::vector<int>(sLength));
        // 初始化:所有长度为1的字串都是回文串
        for (int i = 0; i < sLength; ++i) {
            dp[i][i] = true;
        }

        // 递推开始
        // 先枚举子串长度
        for (int L = 2; L <= sLength; ++L) {
            // 枚举左边界，左边界的上限设置可以宽松一些
            for (int i = 0; i< sLength; ++i) {
                // 由L和i可以确定右边界,即j - i + 1 = L 得
                int j = L + i -1;
                // 如果右边界越界，就可以退出当前循环
                if (j >= sLength) {
                    break;
                }

                if (s[i] != s[j]) {
                    dp[i][j] = false;
                } else {
                    if (j - i < 3) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                }

                // 只要dp[i][L] == true成立，就表示字串s[i..L]是回文，此时记录回文长度和起始位置
                if (dp[i][j] && j - i + 1 > maxLen) {
                    maxLen = j - i + 1;
                    begin = i;
                }
            }
        }

        return s.substr(begin, maxLen);
    }
};

class Solution2 {
public:
    std::string longestPalindrome(std::string s) {
        int start = 0, end = 0;
        for (int i = 0; i < s.size() - 1; ++i) {
            // 从中心开始扩展奇数长度的回文子串
            auto [left1, right1] = expandAroundCenter(s, i, i);
            // 从中心开始扩展偶数长度的回文子串
            auto [left2, right2] = expandAroundCenter(s, i, i + 1);
            if (right1 - left1 > end - start) {
                start = left1;
                end = right1;
            }
            if (right2 - left2 > end - start) {
                start = left2;
                end = right2;
            }
        }
        return s.substr(start, end - start + 1);
    }

private:
    std::pair<int, int> expandAroundCenter(const std::string &s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            --left;
            ++right;
        }
        return {left + 1, right - 1};
    }
};
}

int main(int argc, char** argv) {
    std::string s = "bb";
    std::cout << leetcode_cpp::Solution2().longestPalindrome(s) << std::endl;
}