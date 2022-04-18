#include <bits/stdc++.h>

/*
@
LeetCode
time: 2022-03-25 10:46:20
author: edinw
@
*/

namespace {
class Solution {
public:
    int maximumSwap(int num) {
        std::string s = std::to_string(num);
        int sLen = s.length();
        std::vector<int> buckets(10);

        // Use buckets to record the last position of digit 0 ~ 9 in this num.
        for (int i = 0; i < sLen; ++i) {
            buckets[s[i] - '0'] = i;
        }

        // Loop through the num array from left to right. 
        for (int i = 0; i < sLen; ++i) {
            // For each position, we check whether there exists a larger digit in this num (start from 9 to current digit).
            for (int j = 9; j > s[i] - '0'; --j) {
                //  We also need to make sure the position of this larger digit is behind the current one. 
                if (buckets[j] > i) {
                    // If we find it, simply swap these two digits and return the result.
                    std::swap(s[i], s[buckets[j]]);
                    return std::stoi(s);
                }
            }
        }

        return num;
    }
};
}