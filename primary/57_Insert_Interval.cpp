#include <vector>
#include <iostream>

/*
@
LeetCode HOT 100
time: 2022-02-20 13:39:25
author: edinw
@
*/


namespace leetcode_cpp {
class Solution {
public:
    std::vector<std::vector<int>> insert(std::vector<std::vector<int>>& intervals, std::vector<int>& newInterval) {
        int nSize = intervals.size();
        int left = newInterval[0];
        int right = newInterval[1];
        bool placed = false;
        std::vector<std::vector<int>> ans;
        for (auto &interval: intervals) {
            if (interval[1] < left) {
                ans.emplace_back(interval);
            } else if (interval[0] > right) {
                if (!placed) {  // 当第一次判断newIntervals的时候，如果newInterval在当前interval的右侧，则证明newInterval与所有interval都不重叠
                    ans.emplace_back(std::initializer_list<int>{left, right});
                    placed = true;
                }
                ans.emplace_back(interval);
            } else {
                left = std::min(interval[0], left);
                right = std::max(interval[1], right);
            }
        }

        if (!placed) {
            ans.emplace_back(std::initializer_list<int>{left, right});
        }

        return ans;
    }
};
}

int main(int argc, char **argv) {
    std::vector<std::vector<int>> intervals{{1, 3}, {6, 9}};
    std::vector<int> newInterval{2, 5};
    auto newIntervals = leetcode_cpp::Solution().insert(intervals, newInterval);
    for (const auto &interval: newIntervals) {
        std::cout << interval[0] << ", " << interval[1] << std::endl;
    }

    return 0;
}