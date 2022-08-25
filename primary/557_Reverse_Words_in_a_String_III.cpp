#include <bits/stdc++.h>

/*
@
LeetCode
time: 2022-05-05 15:30:20
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    std::string reverseWords(std::string s) {
        int sLen = s.length();
        int i = 0, start = 0;
        int left = 0, right = 0;
        while (i < sLen) {
            start = i;
            while (i < sLen && ' ' != s[i]) {
                ++i;
            }
            left = start;
            right = i - 1;
            while (left < right) {
                std::swap(s[left++], s[right--]);
            }
            while (i < sLen && ' ' == s[i]) {
                i++;
            }
        }
        return s;
    }
};
}

int main(int argc, char **argv) {
    std::string s{"Let's take LeetCode contest"};
    std::cout << leetcode_cpp::Solution().reverseWords(s) << std::endl;
    return 0;
}