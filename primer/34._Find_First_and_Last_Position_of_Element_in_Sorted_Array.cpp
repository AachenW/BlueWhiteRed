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
#include <limits.h>

/*
@
LeetCode 精选 TOP 面试题
time: 2021-12-17 22:51:51
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    std::vector<int> searchRange(std::vector<int>& nums, int target) {
        int leftIdx = binarySearch(nums, target, true);
        int rightIdx = binarySearch(nums, target, false) - 1;
        if (leftIdx <= rightIdx && rightIdx < nums.size() && nums[leftIdx] == target && nums[rightIdx] == target) {
            return std::vector<int> {leftIdx, rightIdx};
        }
        return std::vector<int> {-1, -1};
    }

private:
    int binarySearch(std::vector<int> &nums, int target, bool lower) {
        int left = 0, right = (int)nums.size() - 1, ans = (int)nums.size();
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (nums[mid] > target || (lower && nums[mid] >= target)) { // 这个判断条件是关键
                right = mid - 1;
                ans = mid;
            } else {    // nums[mid] <= target && ((lower == false) || nums[mid] < target))
                left = mid + 1;
            }
        }
        return ans;
    }
};
}