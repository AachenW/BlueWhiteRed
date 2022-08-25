#include <bits/stdc++.h>

/*
@
projetc: leetcode
time: 2022-05-11 12:25:46  
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int removeCoveredIntervals(std::vector<std::vector<int>> &intervals) {
        std::sort(intervals.begin(), intervals.end(), [](const auto &vec1, const auto &vec2) {
            return vec1[0] != vec2[0] ? vec1[0] < vec2[0] : vec1[1] > vec2[1];
        });
        
        int ans = 0;
        int end = 0, prevEnd = 0;
        for (const auto &interval: intervals) {
            end = interval[1];
            if (prevEnd < end) {
                ++ans;
                prevEnd = end;
            }
        }
        return ans;
    }
};
}

int main(int argc, char **argv) {
    std::vector<std::vector<int>> intervals {{1, 2}, {1, 4}, {3, 4}};
    std::cout << leetcode_cpp::Solution().removeCoveredIntervals(intervals) << std::endl;
    return 0;
}
