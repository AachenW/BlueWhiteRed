#include <bits/stdc++.h>

/*
@
projetc: leetcode
time: 2022-04-04 10:30:47
author: edinw
@
*/

// This is the MountainArray's API interface.
// You should not implement it, or speculate about its implementation
class MountainArray {
  public:
    int get(int index);
    int length();
};

namespace leetcode_cpp {
class Solution {
public:
    public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int left = 0, right = n - 1, mid = 0, peak = 0;

        // find index of peak
        while (left < right) {
            mid = left + ((right - left) >> 1);
            if (mountainArr.get(mid) < mountainArr.get(mid + 1)) {
                left = peak = mid + 1;
            } else {
                right = mid;
            }
        }

        // find target in the left of peak
        left = 0;
        right = peak;
        while (left <= right) {
            mid = left + ((right - left) >> 1);
            if (mountainArr.get(mid) < target) {
                left = mid + 1;
            } else if (mountainArr.get(mid) > target) {
                right = mid - 1;
            } else {
                return mid;
            }
        }

        // find target in the right of peak
        left = peak;
        right = n - 1;
        while (left <= right) {
            mid = left + ((right - left) >> 1);
            if (mountainArr.get(mid) > target) {
                left = mid + 1;
            } else if (mountainArr.get(mid) < target) {
                right = mid - 1;
            } else {
                return mid;
            }
        }

        return -1;
    }
};
}