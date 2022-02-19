#include <iostream>
#include <vector>
#include "limits.h"
#include <unordered_map>
/*
@
project: Leetcode
time: 2022-02-04 20:28:20
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int countGoodRectangles(std::vector<std::vector<int>> &rectangles) {
        int maxLen = INT_MIN;
        std::unordered_map<int, int> cntHash;
        for (const auto sides: rectangles) {
            int side = std::min(sides[0], sides[1]);
            ++cntHash[side];
            maxLen = std::max(maxLen, side);
        }
        return cntHash[maxLen];
    }
};

class Solution2 {
public:
    int countGoodRectangles(std::vector<std::vector<int>> &rectangles) {
        int res = 0, maxLen = 0;
        for (const auto &rectangle: rectangles) {
            int side = std::min(rectangle[0], rectangle[1]);
            if (side == maxLen) {
                ++res;
            } else if (side > maxLen) {
                maxLen = side;
                res = 1;
            }
        }
        return res;
    }
};
}

int main(int argc, char **argv) {
    std::vector<std::vector<int>> rectangles {{2, 3}, {3, 7}, {4, 3}, {3, 7}};
    std::cout << leetcode_cpp::Solution2().countGoodRectangles(rectangles) << std::endl;
    return 0;
}