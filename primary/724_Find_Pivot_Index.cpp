#include <vector>
#include <string>
#include "limits.h"
#include <iostream>
/*
@
LeetCode 剑指offerII
time: 2022-03-04 18:46:18
author: edinw
@
*/

/*
**  Given an array of integers nums, calculate the pivot index of this array.
**
**  The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.
**
**  If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.
**
**  Return the leftmost pivot index. If no such index exists, return -1.
*/

namespace leetcode_cpp {
class Solution {
public:
    int pivotIndex(std::vector<int> &nums) {
        int nSize = nums.size();
        std::vector<int> prefix(nSize + 1);

        for (int i = 1; i <= nSize; ++i) {
            prefix[i] = prefix[i - 1] + nums[i - 1];
        }
        
        int ans = -1;
        for (int i = 1; i <= nSize; ++i) {
            if (prefix[i - 1] == prefix[nSize] - prefix[i]) {
                ans = i - 1;
                break;
            }
        }

        return ans;
    }
};

class Solution2 {
public:
    int pivotIndex(vector<int>& nums) {
        typedef decltype(nums.size()) sz;
        sz nLength = nums.size();
        int total = std::accumulate(nums.begin(), nums.end(), 0);
        int sum = 0;
        for (sz i = 0; i < nLength; ++i) {
            if (2 * sum + nums[i] == total) {
                return i;
            }
            sum += nums[i];
        }
        return -1;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums{1, 7, 3, 6, 5, 6};

    std::cout << leetcode_cpp::Solution().pivotIndex(nums) << std::endl;

    return 0;
}

