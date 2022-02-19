#include <vector>
#include <iostream>
#include "limits.h"
#include <algorithm>
#include <unordered_set>
/*
@
project: leetcode
time: 2022-02-14 20:27:08
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int singleNonDuplicate(std::vector<int> &nums) {
        int nSize = nums.size();
        if (0 == nSize) {
            return 0;
        }
        if (1 == nSize) {
            return nums[0];
        }

        int lo = 0, hi = nSize - 1;
        while (lo < hi) {
            int mid = lo + ((hi - lo) >> 1);
            bool halvesAreEven = (hi - mid) % 2 == 0;
            if (nums[mid + 1] == nums[mid]) {
                if (halvesAreEven) {
                    lo = mid + 2;
                } else {
                    hi = mid - 1;
                }
            } else if (nums[mid - 1] == nums[mid]) {
                if (halvesAreEven) {
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
    std::vector<int> nums {3,3,7,7,10,11,11};
    std::cout << leetcode_cpp::Solution().singleNonDuplicate(nums) << std::endl;
    return 0;
}