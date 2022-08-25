#include <bits/stdc++.h>

/*
@
projetc: leetcode
time: 2022-06-06 17:04:06 
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
    std::map<int, int> mp;
public:
    MyCalendarThree() {
    
    }

    int book(int start, int end) {
        ++mp[start];
        --mp[end];
        int ans = 0;
        int booked = 0;
        for (auto &[_, times]: mp) {
            booked += times;
            ans = std::max(ans, booked);
        }

        return ans;
    }
};
}

