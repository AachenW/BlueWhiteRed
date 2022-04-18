#include <vector>
#include <iostream>
#include <deque>
#include "limits.h"
#include <algorithm>

/*
@
LeetCode
time: 2022-03-17 10:13:34
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int findMin(std::vector<int>& nums) {
        int nSize = nums.size();
        int lo = 0, hi = nSize - 1;

        // 由于数组不包含重复元素，并且只要当前的区间长度不为 1，mid 就不会与 hi 重合；而如果当前的区间长度为 1，这说明我们已经可以结束二分查找了。
        while (lo < hi) {
            int mid = lo + ((hi - lo) >> 1);
            if (nums[mid] < nums[hi]) {
                hi = mid;
            } else if (nums[mid] > nums[hi]){
                lo = mid + 1;
            } else {
                hi -= 1;
            }
        }

        return nums[lo];
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums{3, 4, 5, 1, 2};
    
    std::cout << leetcode_cpp::Solution().findMin(nums) << std::endl;

    return 0;
}