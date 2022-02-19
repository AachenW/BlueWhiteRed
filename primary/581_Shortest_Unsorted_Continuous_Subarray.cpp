#include <vector>
#include <iostream>
#include "limits.h"
#include <algorithm>

/*
@
project: leetcode
time: 2022-02-02 21:35:48
author: edinw
@
*/

/*
**  Given an integer array nums, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array 
**      will be sorted in ascending order.
**  Return the shortest such subarray and output its length.
*/

namespace leetcode_cpp {
class Solution {
public: 
    int findUnsortedSubarray(std::vector<int> &nums) {
        if (std::is_sorted(nums.begin(), nums.end())) {
            return 0;
        }
        std::vector<int> originalNums(nums);
        std::sort(nums.begin(), nums.end());
        
        int nLen = nums.size();
        int left = 0;
        while (originalNums[left] == nums[left]) {
            ++left;
        }
        int right = nLen - 1;
        while (originalNums[right] == nums[right]) {
            --right;
        }

        return right - left + 1;
    }
};

class Solution2 {
public:
    int findUnsortedSubarray(std::vector<int> &nums) {
        int nLen = nums.size();
        int maxn = INT_MIN, right = -1;
        int minn = INT_MAX, left = -1;
        for (int i = 0; i < nLen; ++i) {
            // 从左往右，找到比左边最大值还小的最右下标
            if (nums[i] >= maxn) {
                maxn = nums[i];
            } else {
                right = i;
            }
            // 从右往左，找到比右边最小值还大的最左下标
            if (minn < nums[nLen - i - 1]) {
                left = nLen - i - 1;
            } else {
                minn = nums[nLen - i - 1];
            }
        }

        return right == -1 ? 0 : right - left + 1;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums {2,3,3,2,4};
    std::cout << leetcode_cpp::Solution2().findUnsortedSubarray(nums) << std::endl;
    return 0;
}