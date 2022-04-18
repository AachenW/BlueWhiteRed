#include <vector>
#include <string>
#include <iostream>

/*
@
LeetCode
time: 2022-03-20 16:30:51
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
    std::vector<std::vector<int>> generate(int numRows) {
        std::vector<std::vector<int>> ret(numRows);
        for (int i = 0; i < numRows; ++i) {
            ret[i].resize(i + 1);
            ret[i][0] = ret[i][i] = 1;
            for (int j = 1; j < i; ++j) {
                ret[i][j] = ret[i - 1][j] + ret[i - 1][j - 1];
            }
        }
        return ret;
    }
};
}