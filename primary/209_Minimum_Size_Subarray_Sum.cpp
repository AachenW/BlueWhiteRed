#include <vector>
#include <algorithm>
#include <iostream>
#include "limits.h"
/*
@
project: Leetcode
time: 2022-03-04 16:29:43
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int minSubArrayLen(int s, std::vector<int> &nums) {
        int nSize = nums.size();
        if (0 == nSize) {
            return 0;
        }

        int ans = INT_MAX;
        std::vector<int> sums(nSize + 1, 0);

        for (int i = 1; i <= nSize; ++i) {
            sums[i] = sums[i - 1] + nums[i - 1];
        }

        for (int i = 1; i <= nSize; ++i) {
            int target = s + sums[i - 1];
            auto bound = std::lower_bound(sums.begin(), sums.end(), target);
            if (bound != sums.end()) {
                ans = std::min(ans, static_cast<int>(bound - sums.begin()) - (i - 1));
            }
        }

        return ans == INT_MAX ? 0 : ans;
    }
};

class Solution2 {
public:
    int minSubArrayLen(int s, std::vector<int> &nums) {
        int nSize = nums.size();
        if (0 == nSize) {
            return 0;
        }

        int ans = INT_MAX;
        int lo = 0, hi = 0;
        int sum = 0;
        
        while (hi < nSize) {
            sum += nums[hi];
            while (sum >= s) {
                ans = std::min(ans, hi - lo + 1);
                sum -= nums[lo];
                ++lo;
            }
            ++hi;
        }

        return ans == INT_MAX ? 0 : ans;
    }
};
}

int main(int argc, char **argv) {
    int target = 7;
    std::vector<int> nums{2, 3, 1, 2, 4, 3};

    std::cout << leetcode_cpp::Solution().minSubArrayLen(target, nums) << std::endl;

    return 0;
}
