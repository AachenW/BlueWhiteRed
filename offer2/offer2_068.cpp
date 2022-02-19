#include <iostream>
#include <vector>
#include <string>
#include "limits.h"
/*
@
LeetCode 剑指offerⅡ
time: 2022-01-24 19:32:43
author: edinw
@
*/

/*
**  注意：本题与主站 35 题相同： https://leetcode-cn.com/problems/search-insert-position/
** 
**  Given a sorted array of distinct integers and a target value, return the index if the target is found. If not, return the index where it would be if 
**  it were inserted in order.
**  You must write an algorithm with O(log n) runtime complexity.
*/

namespace leetcode_cpp {
class Solution {
public:
    int searchInsert(std::vector<int> &nums, int target) {
        int nLength = nums.size();
        if (0 == nLength) {
            return -1;
        }
        int lo = 0, hi = nLength - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) >> 1;
            if (nums[mid] == target) {
                return mid;
            } else if (nums[mid] > target) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        if (nums[lo] < target) {
            return lo + 1;
        } else {
            return lo - 1;
        }
    }
};
}


int main(int argc, char **argv) {
    std::vector<int> nums {1, 3, 5, 6};
    int target = 7;
    std::cout << leetcode_cpp::Solution().searchInsert(nums, target) << std::endl;
    return 0;
}