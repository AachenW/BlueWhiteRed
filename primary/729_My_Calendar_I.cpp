#include <map>

/*
@
LeetCode 剑指offerⅡ
time: 2022-03-06 21:57:48
author: edinw
@
*/

namespace leetcode_cpp {
class MyCalendar {
    std::map<int, int> events;
public:
    MyCalendar() {
    
    }

    bool book(int start, int end) {
        auto it = events.lower_bound(start);
        // 与后一个时间段重叠
        if (it != events.end() && it->first < end) {
            return false;
        }
        // 与前一个时间段重叠
        if (it != events.begin() && (--it)->second > start) {
            return false;
        }

        events[start] = end;
        return true;
    }
};
}
