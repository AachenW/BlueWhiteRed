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
    int countSubstring(std::string &s) {
        int sLen = s.length();
        int ans = 0;

        for (int i = 0; i < sLen; ++i) {
            for (int j = 0; j <= 1; ++j) {
                int lo = i;
                int hi = i + j;
                while (lo >= 0 && hi < sLen && s[lo] == s[hi]) {
                    --lo;
                    ++hi;
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

    std::cout << leetcode_cpp::Solution().countSubstring(s) << std::endl;

    return 0;
}
