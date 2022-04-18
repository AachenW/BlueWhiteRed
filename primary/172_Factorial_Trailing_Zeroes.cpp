#include <bits/stdc++.h>

/*
@
LeetCode
time: 2022-03-20 19:01:40
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int trailingZeros(int n) {
        int ans = 0;
        for (int i = 5; i <= n; ++i) {
            int j = i;
            while (j) {
                if (0 == j % 5) {
                    ++ans;
                    j /= 5;
                } else {
                    break;
                }
            }
        }

        return ans;
    }
};
}