#include <bits/stdc++.h>

/*
@
project: leetcode
time: 2022-03-28 20:43:23
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int findMinArrowShots(std::vector<std::vector<int>>& points) {
        int pSize = points.size();
        if(pSize <= 1) return pSize;

        std::sort(points.begin(),points.end());
        int right = points[0][1], ans = 1;
        for(int i = 0; i < pSize; ++i){
            if(right < points[i][0]){
                right = points[i][1];
                ++ans;
            } else {
                right > points[i][1] ? right = points[i][1] : right;
            }
        }
        return ans;
    }
};
}