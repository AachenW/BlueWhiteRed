#include <iostream>
#include <vector>
#include <algorithm>
/*
@
LeetCode HOT 100
time: 2022-02-06 21:19:34
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>> &intervals) {
        std::sort(intervals.begin(), intervals.end());
        std::vector<std::vector<int>> ans;
        for (int i = 0; i < intervals.size(); ++i) {
            int left = intervals[i][0];
            int right = intervals[i][1];
            if (ans.empty() || ans.back()[1] < left) {
                ans.emplace_back(std::initializer_list<int>{left, right});
            } else {
                ans.back()[1] = std::max(ans.back()[1], right);
            }
        }
        return ans;
    }
};
}

int main(int argc, char **argv) {
    std::vector<std::vector<int>> intervals{{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    auto ans = leetcode_cpp::Solution().merge(intervals);
    for (const auto &nums: ans) {
        std::cout << nums[0] << " " << nums[1] << std::endl;
    }

    return 0;
}