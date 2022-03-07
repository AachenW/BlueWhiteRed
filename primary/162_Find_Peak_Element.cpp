#include <vector>
#include <string>
#include <iostream>
#include "../lib/ListNode.h"
#include "limits.h"
/*
@
LeetCode
time: 2022-02-26 19:34:05
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int findPeakElement(std::vector<int> &nums) {
        int nSize = nums.size();
        if (1 == nSize || nums[0] > nums[1]) {
            return 0;
        }
        if (nums[nSize - 1] > nums[nSize - 2]) {
            return nSize - 1;
        }

        // 此时可以保证第一个元素和最后一个元素值都比相邻的要小, 采用第二个和倒数第二个元素作为左右边界
        int lo = 1, hi = nSize - 2;

        while (lo <= hi) {
            int mid = lo + ((hi - lo) >> 1);
            if (nums[mid] > nums[mid + 1] && nums[mid] > nums[mid - 1]) {
                return mid;
            } else if (nums[mid] < nums[mid + 1]) {
                lo = mid + 1;
            } else if (nums[mid] > nums[mid + 1]){
                hi = mid - 1;
            }
        }

        return -1;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums {1, 3, 2, 1};
    std::cout << leetcode_cpp::Solution().findPeakElement(nums) << std::endl;

    return 0;
}