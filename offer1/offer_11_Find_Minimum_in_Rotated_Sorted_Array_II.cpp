#include <vector>
#include <iostream>
#include <algorithm>
#include "limits.h"
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
            int pivot = lo + ((hi - lo) >> 1);
            if (nums[pivot] < nums[hi]) {
                hi = pivot;             // 忽略二分查找右半部分，pivot有可能是最小值的下标，所以不能直接跳过
            } else if (nums[pivot] > nums[hi]) {
                lo = pivot + 1;         // 忽略二分查找左半部分，pivot不可能是最小值的下标，所以可以直接跳过
            } else {
                // 由于重复元素的存在，我们并不能确定 numbers[pivot] 究竟在最小值的左侧还是右侧，因此我们不能莽撞地忽略某一部分的元素。我们唯一可以知道的是，由于它们的值相同，所以无论 numbers[high] 是不是最小值，都有一个它的「替代品」 numbers[pivot]，因此我们可以忽略二分查找区间的右端点。
                hi -= 1;                
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