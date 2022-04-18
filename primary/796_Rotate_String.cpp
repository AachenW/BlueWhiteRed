#include <bits/stdc++.h>

namespace leetcode_cpp {
class Solution {
public:
    bool rotateString(std::string s, std::string goal) {
        if (s.length() != goal.length()) {
            return false;
        } 

        int sLen = s.length(), gLen = goal.length();
        int flag = 0;
        for (int i = 0; i < sLen; ++i) {
            flag = 0;
            for (int j = 0; j < gLen; ++j) {
                if (s[(i + j) % sLen] != goal[j]) {
                    flag = 1;
                    break;
                }
            }

            if (!flag) {
                return true;
            }
        }

        return false;
    } 
};
}