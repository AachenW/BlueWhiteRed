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

/*
**  由于只出现一次的元素所在下标 x 的左边有偶数个元素，因此下标 x 一定是偶数，可以在偶数下标范围内二分查找。二分查找的目标是找
**  到满足 nums[x] != nums[x+1] 的最小的偶数下标 x，则下标 x 处的元素是只出现一次的元素。
*/
class Solution {
public:
    int singleNonDuplicate(std::vector<int> &nums) {
        int lo = 0, hi = nums.size() - 1;

        while (lo < hi) {
            int mid = lo + ((hi - lo) >> 1);
            mid -= mid & 1; // 将mid移动到靠左的偶数索引下
            if (nums[mid] == nums[mid + 1]) {
                lo = mid + 2;
            } else {
                hi = mid;
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
