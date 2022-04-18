#include <bits/stdc++.h>

/*
@
project: leetcode
time: 2022-03-29 21:22:48
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    bool judgeSquareSum(int c) {
        long left = 0, right = (int)std::sqrt(c);

        while (left <= right) {
            long sum = left * left + right * right;
            if (sum == c) {
                return true;
            } else if (sum > c) {
                --right;
            } else {
                ++left;
            }
        }

        return false;
    }
};
}