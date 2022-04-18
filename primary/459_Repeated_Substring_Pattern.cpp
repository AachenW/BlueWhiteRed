#include <bits/stdc++.h>

/*
@
project: leetcode
time: 2022-03-28 19:24:57
author: edinw
@
*/

class Solution {
public:
    bool repeatedSubstringPattern(std::string s) {
        return (s + s).substr(1, 2 * s.size() - 2).find(s) != -1;
    }
};