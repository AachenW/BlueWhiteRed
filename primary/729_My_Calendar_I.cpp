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
    std::map<int, int> mp;
public:
    MyCalendar() {

    }
    
    bool book(int start, int end) {
        ++mp[start];
        --mp[end];
        int booked = 0;
        for (auto &[_, times]: mp) {
            booked += times;
            if (booked > 1) {
                --mp[start];
                ++mp[end];
                return false;
            }
        }
        return true;
    }
};
}
