#include <vector>
#include <algorithm>
#include <set>
#include <iostream>
#include "limits.h"

/*
@
LeetCode 剑指offerⅡ
time: 2022-03-06 21:35:40
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    bool containNearbyAlmostDuplicate(std::vector<int> &nums, int k, int t) {
        std::set<int> st;
        int nSize = nums.size();

        for (int i = 0; i < nSize; ++i) {
            int lowerLimit = std::max(nums[i], INT_MIN + t) - t;
            int upperLimit = std::min(nums[i], INT_MAX - t) + t;
            auto it = st.lower_bound(lowerLimit);
            if (it != st.end() && *it <= upperLimit) {
                return true;
            }

            st.insert(nums[i]);

            if (i >= k) {
                st.erase(nums[i - k]);
            }
        }

        return false;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums{1, 2, 3, 1};
    int k = 3, t = 0;

    std::cout << std::boolalpha << leetcode_cpp::Solution().containNearbyAlmostDuplicate(nums, k, t) << std::endl;

    return 0;
}
