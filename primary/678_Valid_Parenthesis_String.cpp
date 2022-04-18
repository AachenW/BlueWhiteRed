#include <bits/stdc++.h>

/*
@
LeetCode
time: 2022-03-23 17:24:56
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    bool checkValidString(std::string s) {
        int cmin = 0, cmax = 0; // left parenthese count in range [cmin, cmax]

        for (auto &&c: s) {
            if ('(' == c) {
                ++cmin;
                ++cmax;
            } else if (')' == c) {
                --cmin;
                --cmax;
            } else if ('*' == c) {
                ++cmax; // if '*' become '(' then openCount++
                --cmin; // if '*' become ')' then openCount--;
                // if '*' become ' ', then nothing happens, so openCount will be in new range [cmin - 1, cmax + 1];
            }

            if (cmax < 0) {
                return false;   // currently, don't have enough open parenthese to match close parenthese -> invalid
            }
            cmin = std::max(cmin, 0);   // It's invalid if open parenthese count < 0 that's why cmin can't be negative
        }

        return 0 == cmin;   // Return true if can found `openCount == 0` in range [cmin, cmax]
    }
};
}

int main(int argc, char **argv) {
    std::string{"()"};

    std::cout << std::boolalpha << leetcode_cpp::Solution().checkValidString(s) << std::endl;

    return 0;
}