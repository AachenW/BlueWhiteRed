#include <bits/stdc++.h>

/*
@
projetc: leetcode
time: 2022-06-06 16:53:35 
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
    std::map<int, int> mp; // key: time; val: +1 if start, -1 if end
public:
    MyCalendarTwo() {
    
    }

    bool book(int start, int end) {
        ++mp[start];
        --mp[end];
        int booked = 0;
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            booked += it->second;
            // 若存在重合的日程
            if (3 == booked) {
                --mp[start];
                ++mp[end];
                return false;
            }
        }
        return true;
    }
};
}

int main(int argc, char **argv) {
    
}
