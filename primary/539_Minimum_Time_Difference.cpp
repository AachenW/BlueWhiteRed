#include <vector>
#include <iostream>
#include "limits.h"
#include <algorithm>
/*
@
project: leetcode
time: 2022-01-18 19:49:34
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int findMinDifference(std::vector<std::string> &timePoints) {
        if (timePoints.size() > 24 * 60) {
            return 0;
        } 

        std::vector<int> minutes;
        for (const auto& time: timePoints) {
            minutes.emplace_back(stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3)));
        } 

        std::sort(minutes.begin(), minutes.end());
        minutes.emplace_back(minutes.front() + 24 * 60);

        int minDiff = INT_MAX;
        int mSize = minutes.size();
        for (int i = 1; i < mSize; ++i) {
            minDiff = std::min(minDiff, minutes.at(i) - minutes.at(i - 1));
        }
        return minDiff;
    }
};
}

int main(int agrc, char **argv) {
    std::vector<std::string> timePoints {"00:00", "23:59", "00:00"};
    std::cout << leetcode_cpp::Solution().findMinDifference(timePoints) << std::endl;
    return 0;
}