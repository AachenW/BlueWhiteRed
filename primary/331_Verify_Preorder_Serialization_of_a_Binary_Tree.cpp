#include <bits/stdc++.h>

/*
@
LeetCode
time: 2022-04-04 19:28:58
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    bool isValidSerialization(std::string preorder) {
        std::vector<std::string> nodes;
        std::stringstream ss(preorder);
        std::string s;

        while (std::getline(ss, s, ',')) {
            nodes.emplace_back(s);
        }

        int diff = 1;
        for (std::string node: nodes) {
            diff -= 1;
            if (diff < 0) {
                return false;
            }
            if ("#" != node) {
                diff += 2;
            }
        }

        return 0 == diff;
    }
};
}