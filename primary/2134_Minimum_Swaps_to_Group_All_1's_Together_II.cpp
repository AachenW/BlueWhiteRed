#include <iostream>
#include <vector>
#include "limits.h"

/*
@
project: Leetcode
time: 2022-03-07 12:18:46
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int minSwaps(std::vector<int> &nums) {
        int k = 0;  // 维护一个大小为nums中1的总数的滑动窗口
        for (auto &&num: nums) {
            if (1 == num) {
                ++k;
            }
        }

        if (0 == k) {
            return 0;
        }

        std::vector<int> ring = nums;
        // 由于要考虑处理环状数组，所以将num再拼接一次，在新的数组中使用滑窗维护答案即可
        ring.insert(ring.end(), nums.begin(), nums.end());
        int n  = ring.size();
        int cnt = 0, ans = INT_MAX;
        for (int i = 0; i < n; ++i) {
            if (1 == ring[i]) { // 右边界滑动
                ++cnt;
            }
            if (i >= k - 1) {
                ans = std::min(ans, k - cnt); // 窗口临界，比较当前窗口内0的个数是否最小
                if (1 == ring[i - k + 1]) {
                    --cnt;  // 左边界滑动
                }
            }
        }

        return ans;
    }
};
}