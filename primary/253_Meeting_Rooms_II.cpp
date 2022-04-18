#include <bits/stdc++.h>

/*
@
projetc: leetcode
time: 2022-04-01 19:33:22
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int minMeetingRooms(std::vector<std::vector<int>>& intervals) {
        if (intervals.empty()) {
            return 0;
        }

        std::sort(intervals.begin(), intervals.end(), [&](auto a, auto b) {
            if (a[0] == b[0]) {
                return a[1] < b[1]; // 开始时间一样，先结束的在前
            }
            return a[0] < b[0]; // 开始早的在前
        });

        std::priority_queue<int, std::vector<int>, std::greater<>> pq;
        pq.emplace(intervals[0][1]);

        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] >= pq.top()) {
                pq.pop();
            }
            pq.emplace(intervals[i][1]);
        }

        return pq.size();
    }
};
}