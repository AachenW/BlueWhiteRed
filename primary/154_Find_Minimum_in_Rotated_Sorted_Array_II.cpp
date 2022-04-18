#include <bits/stdc++.h>

/*
@
LeetCode 剑指offer
time: 2022-02-01 15:09:31
author: edinw
@
*/

/*
**  注意：本题与主站 154 题相同：https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/
** 
**  Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,4,4,5,6,7] might become:
**      [4,5,6,7,0,1,4] if it was rotated 4 times.
**      [0,1,4,4,5,6,7] if it was rotated 7 times.
**  Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].
**  Given the sorted rotated array nums that may contain duplicates, return the minimum element of this array.
**  You must decrease the overall operation steps as much as possible.
*/

namespace leetcode_cpp {
class Solution {
public:
    int minArray(std::vector<int> &nums) {
        int lo = 0, hi = nums.size() - 1;

        while (lo < hi) {
            int mid = lo + ((hi - lo) >> 1);
            if (nums[mid] <= nums[hi]) {
                hi -= 1;
            } else {
                lo = mid + 1;
            }
        }
        return nums[lo];
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums {1, 3, 3};
    std::cout << leetcode_cpp::Solution().minArray(nums) << std::endl;
    return 0;
}