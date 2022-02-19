#include <iostream>
#include <vector>
#include <algorithm>
/*
@
LeetCode 剑指offerⅡ
time: 2022-01-25 20:25:36
author: edinw
@
*/

/*
**  注意：本题与主站 56 题相同： https://leetcode-cn.com/problems/merge-intervals/
** 
**  Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.
*/

namespace leetcode_cpp {
class Solution {
public:
    std::vector<std::vector<int>> merge(std::vector<std::vector<int>> &intervals) {
        std::sort(intervals.begin(), intervals.end());
        std::vector<std::vector<int>> ans;
        for (int i = 0; i < intervals.size(); ++i) {
            int left = intervals[i][0], right = intervals[i][1];
            if (!ans.size() || ans.back()[1] < left) {
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
    std::vector<std::vector<int>> intervals{{1, 4}, {4, 5}, {8, 10}, {15, 18}};
    auto ans = leetcode_cpp::Solution().merge(intervals);
    for (const auto &output: ans) {
        std::cout << output[0] << " " << output[1] << std::endl;
    }

    return 0;
}