#include <bits/stdc++.h>

/*
@
LeetCode
time: 2022-03-24 12:10:48
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    std::vector<int> nextGreaterElements(std::vector<int>& nums) {
        int nSize = nums.size();
        if (0 == nSize) {
            return {};
        }

        std::vector<int> mono_stack;
        std::vector<int> ans(nSize, -1);
        for (int i = 0; i < nSize * 2 - 1; ++i) {
            while (!mono_stack.empty() && nums[mono_stack.back()] < nums[i % nSize]) {
                int idx = mono_stack.back(); mono_stack.pop_back();
                ans[idx] = nums[i % nSize];
            }
            mono_stack.emplace_back(i % nSize);
        }

        return ans;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums{1, 2, 1};

    auto ans = leetcode_cpp::Solution().nextGreaterElements(nums);
    
    for (int output: ans) {
        std::cout << output << ",";
    }
    std::cout << std::endl;

    return 0;
}