#include <bits/stdc++.h>

/*
@
projetc: leetcode
time: 2022-03-23 13:57:18
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int calculate(std::string s) {
        std::vector<int> stk;
        stk.emplace_back(1);
        int sign = 1;

        int ret = 0;
        int sLen = s.length();
        int i = 0;
        while (i < sLen) {
            if (' ' == s[i]) {
                ++i;
            } else if ('+' == s[i]) {
                sign = stk.back();
                ++i;
            } else if ('-' == s[i]) {
                sign = -stk.back();
                ++i;
            } else if ('(' == s[i]) {
                stk.emplace_back(sign);
                ++i;
            } else if (')' == s[i]) {
                stk.pop_back();
                ++i;
            } else {
                long num = 0;
                while (i < sLen && s[i] >= '0' && s[i] <= '9') {
                    num = num * 10 + s[i] - '0';
                    ++i;
                }
                ret += sign * num;
            }
        }

        return ret;
    }
};
}