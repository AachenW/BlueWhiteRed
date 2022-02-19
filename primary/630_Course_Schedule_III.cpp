#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <ctime>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cstdlib>
#include <numeric>

/*
@
project: leetcode
time: 2021-12-14 22:16:25
author: edinw
@
*/

namespace leetcode_cpp {
class Solution{
public:
    int scheduleCourse(std::vector<std::vector<int>>& courses) {
        // 以结束时间排序
        std::sort(courses.begin(), courses.end(), [](const auto& c0, const auto& c1) {
            return c0[1] < c1[1];
        });
        std::priority_queue<int> q;
        // 优先队列中所有课程的总时间
        int total = 0;
        for (const auto& course: courses) {
            int ti = course[0], di = course[1];
            if (total + ti <= di) {
                total += ti;
                q.push(ti);
            } else if(!q.empty() && q.top() > ti) {
                total -= q.top() - ti;
                q.pop();
                q.push(ti);
            }
        }
        return q.size();
    }
};
}