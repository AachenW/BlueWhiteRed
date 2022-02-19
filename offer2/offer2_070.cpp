#include <iostream>
#include <vector>
#include <string>
#include "limits.h"
/*
@
LeetCode 剑指offerⅡ
time: 2022-01-24 20:09:15
author: edinw
@
*/

/*
**  注意：本题与主站 540 题相同：https://leetcode-cn.com/problems/single-element-in-a-sorted-array/
** 
**  You are given a sorted array consisting of only integers where every element appears exactly twice, except for one element which appears exactly 
**  once.
**  Return the single element that appears only once.
**  Your solution must run in O(log n) time and O(1) space.
*/

namespace leetcode_cpp {
class Solution {
public:
    int singleNonDuplicate(std::vector<int> &nums) {
        auto nLength = nums.size();
        if (nLength & 1 == 0) {
            return -1;
        }
        int lo = 0, hi = nLength - 1;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            bool halvesAreEven = (hi - mid) % 2 == 0;
            if (nums[mid + 1] == nums[mid]) {
                if (halvesAreEven) {
                    lo = mid + 2;
                } else {
                    hi = mid - 1;
                }
            } else if (nums[mid - 1] == nums[mid]) {
                if(halvesAreEven) {
                    hi = mid - 2;
                } else {
                    lo = mid + 1;
                }
            } else {
                return nums[mid];
            }
        }
        return nums[lo];
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums {1, 1, 2, 3, 3, 4, 4, 8, 8};
    std::cout << leetcode_cpp::Solution().singleNonDuplicate(nums) << std::endl;
    return 0;
}