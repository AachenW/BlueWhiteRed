#include <string>
#include <iostream>

/*
@
LeetCode 剑指offerⅡ
time: 2022-01-01 22:08:59
author: edinw
@
*/

/*
本题与主站 680 题相同： https://leetcode-cn.com/problems/valid-palindrome-ii/
给定一个非空字符串 s，请判断如果 最多 从字符串中删除一个字符能否得到一个回文字符串。
*/

namespace leetcode_cpp {
class Solution {
public:
    bool validPalindrome(std::string s) {
        int lo = 0, hi = s.size() - 1;
        while (lo < hi) {
            char c1 = s[lo], c2 = s[hi];
            if (c1 == c2) {
                ++lo;
                --hi;
            } else {
                // 贪心选择，删除最左字符判断是否为回文串或者删除最右字符判断是否为回文串
                return palindrome(s, lo + 1, hi) || palindrome(s, lo, hi - 1);
            }
        }
        return true;
    }

private:
    bool palindrome(const std::string &s, int low, int high) {
        for (int i = low, j = high; i < j; ++i, --j) {
            if (s[i] != s[j]) {
                return false;
            }
        }
        return true;
    }
};
}

int main (int argc, char **argv) {
    std::string s{"abc"};
    std::cout << leetcode_cpp::Solution().validPalindrome(s) << std::endl;
    return 0;
}