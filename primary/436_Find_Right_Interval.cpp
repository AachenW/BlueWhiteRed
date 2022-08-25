#include <bits/stdc++.h>

/*
@
projetc: leetcode
time: 2022-05-20 20:21:19 
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    std::vector<int> findRightInterval(std::vector<std::vector<int>> &intervals) {
        std::vector<std::pair<int, int>> startIntervals;
        std::vector<std::pair<int, int>> endIntervals;
        int n = intervals.size();
        for (int i = 0; i < n; ++i) {
            startIntervals.emplace_back(intervals[i][0], i);
            endIntervals.emplace_back(intervals[i][1], i);
        }
        std::sort(startIntervals.begin(), startIntervals.end());
        std::sort(endIntervals.begin(), endIntervals.end());

        std::vector<int> ans(n, -1);
        for (int i = 0, j = 0; i < n && j < n; ++i) {
            while (j < n && endIntervals[i].first > startIntervals[j].first) ++j;
            // startIntervals[j - 1][0] < endIntervals[i][0] <= endIntervals[j][0]
            if (j < n) ans[endIntervals[i].second] = startIntervals[j].second;
        }
        return ans;
    }
};
}

int main(int argc, char **argv) {
    std::vector<std::vector<int>> intervals{{3, 4}, {2, 3}, {1, 2}};
    auto ans = leetcode_cpp::Solution().findRightInterval(intervals);
    for (int output: ans) std::cout << output << ",";
    std::cout << std::endl;
    return 0;
}
