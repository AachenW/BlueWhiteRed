#include <vector>
#include <iostream>
#include <deque>
#include "limits.h"
#include <algorithm>
/*
@
LeetCode 热题 HOT 100
time: 2022-01-29 21:30:37
author: edinw
@
*/

/*
**  Given an integer array nums, find a contiguous non-empty subarray within the array that has the largest product, and return the product.
**  The test cases are generated so that the answer will fit in a 32-bit integer.
**  A subarray is a contiguous subsequence of the array.
*/

namespace leetcode_cpp {
class Solution {
public:
    int maxProduct(std::vector<int> &nums) {
        int nLength = nums.size();
        int lo = 0, hi = 0;
        int maxAns = INT_MIN;
        int ans = 1;
        while (hi < nLength) {
            if (hi == nLength) {
                ans /= nums[lo++];
            } else {
                if (0 != nums[hi]) {
                    ans *= nums[hi++];
                } else if (lo < hi) {
                    ans /= nums[lo++];
                } else {
                    maxAns = std::max(maxAns, 0);
                    ++lo;
                    ++hi;
                }
            }
            if (lo != hi) {
                maxAns = std::max(maxAns, ans);
            }
        }
        return maxAns;
    }
};

class Solution2 {
public:
    int maxProduct(std::vector<int> &nums) {
        std::vector<int> maxF(nums), minF(nums);
        for (int i = 1; i < nums.size(); ++i) {
            maxF[i] = std::max(maxF[i - 1] * nums[i], std::max(minF[i - 1] * nums[i], nums[i]));
            minF[i] = std::min(maxF[i - 1] * nums[i], std::min(minF[i - 1] * nums[i], nums[i]));
        }
        return *std::max_element(maxF.begin(), maxF.end());
    }
};

class Solution3 {
public:
    int maxProduct(std::vector<int> &nums) {
        int maxF = nums[0];
        int minF = nums[0];
        int ans = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            int mx = maxF, mn = minF;
            maxF = std::max(mx * nums[i], std::max(mn * nums[i], nums[i]));
            minF = std::min(mx * nums[i], std::min(mn * nums[i], nums[i]));
            ans = std::max(maxF, ans);
        }
        return ans;
    }
};

class Solution4 {
public:
    int maxProduct(std::vector<int> &nums) {
        // store the result that is the max we have found so far
        int r = nums[0];
        int nSize = nums.size();
        // imax/imin stores the max/min product of subarray that ends with the current number nums[i];
        for (int i = 1, imax = r, imin = r; i < nSize; ++i) {
            // multiplied by a negative makes big number smaller, small number bigger, so we redefine the extremums by swapping them
            if (nums[i] < 0) {
                std::swap(imax, imin);
            }

            // max/min product for the current number is either the current number itself, or the max/min by the previous number times the current one
            imax = std::max(nums[i], imax * nums[i]);
            imin = std::min(nums[i], imin * nums[i]);

            r = std::max(r, imax);
        }

        return r;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums{2,3,-2,4};
    std::cout << leetcode_cpp::Solution().maxProduct(nums) << std::endl;
    return 0;
}