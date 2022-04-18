#include <bits/stdc++.h>

/*
@
projetc: leetcode
time: 2022-03-31 17:54:15
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    bool carPooling(std::vector<std::vector<int>> &trips, int capacity) {
        std::vector<std::pair<int, int>> v;

        for (int i = 0; i < trips.size(); ++i) {
            v.emplace_back(std::make_pair(trips[i][1], trips[i][0]));   // at fromi location curr will be increased by numPassengersi
            v.emplace_back(std::make_pair(trips[i][2], -trips[i][0]));  // at toi location curr will be decreased by numPassengersi
        }

        std::sort(v.begin(), v.end());

        // let curr be the number of passengers currently in the car. so initially curr = 0
        int curr = 0;

        for (int i = 0; i < v.size(); ++i) {
            curr += v[i].second;
            if (curr > capacity) {
                return false;   // at any point of time , if curr>capacity , just return false
            }
        }

        return true;
    }
};
}