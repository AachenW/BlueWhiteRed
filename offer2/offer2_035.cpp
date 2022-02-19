#include <vector>
#include <iostream>
#include <algorithm>
/*
@
LeetCode 剑指offerⅡ
time: 2022-01-08 22:33:23
author: edinw
@
*/

/*
注意：本题与主站 539 题相同： https://leetcode-cn.com/problems/minimum-time-difference/

给定一个 24 小时制（小时:分钟 "HH:MM"）的时间列表，找出列表中任意两个时间的最小时间差并以分钟数表示。
*/

namespace leetcode_cpp {
class Solution {
public:
    int findMinDifference(std::vector<std::string> &timePoints) {
        // 时间点最多只有 24 * 60 个，因此，当 timePoints 长度超过 24 * 60，说明有重复的时间点，提前返回 0
        if (timePoints.size() > 24 * 60) {
            return 0;
        }

        std::vector<int> mins;
        // 遍历时间列表，将其转换为“分钟制”列表 mins
        for (const auto &t : timePoints) {
            mins.emplace_back(stoi(t.substr(0, 2)) * 60 + stoi(t.substr(3)));
        }
        // 接着将“分钟制”列表按升序排列
        sort(mins.begin(), mins.end());
        // 将此列表的最小时间 mins[0] 加上 24 * 60 追加至列表尾部，用于处理最大值、最小值的差值这种特殊情况
        mins.emplace_back(mins[0] + 24 * 60);
        int res = 24 * 60;
        int minsSize = mins.size();
        // 遍历“分钟制”列表，找出相邻两个时间的最小值即可
        for (int i = 1; i < minsSize; ++i) {
            res = std::min(res, mins[i] - mins[i - 1]);
        }
        return res;
    }
};
}

int main (int argc, char **argv) {
    std::vector<std::string> timePoints {"00:00","23:59","00:00"};
    std::cout << leetcode_cpp::Solution().findMinDifference(timePoints) << std::endl;
    return 0;
}