#include <bits/stdc++.h>

/*
@
Leetcode
time: 2022-03-23 21:50:58
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    // 在遍历数组时，我们不访问最后一个元素，这是因为在访问最后一个元素之前，我们的边界一定大于等于最后一个位置，否则就无法跳到最后一个位置了。如果访问最后一个元素，在边界正好为最后一个位置的情况下，我们会增加一次「不必要的跳跃次数」，因此我们不必访问最后一个元素。
    int jump(std::vector<int> &nums) {
        int nSize = nums.size();
        int ans = 0, end = 0, maxReach = 0;

        for (int i = 0; i < nSize - 1; ++i) {
            if (i <= maxReach) {
                maxReach = std::max(maxReach, i + nums[i]);
                if (i == end) {
                    end = maxReach;
                    ++ans;
                }
            } else {
                return 0;
            }
        }

        return ans;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums{2, 3, 1, 1, 4};
    std::cout << leetcode_cpp::Solution().jump(nums) << std::endl;
    return 0;
}