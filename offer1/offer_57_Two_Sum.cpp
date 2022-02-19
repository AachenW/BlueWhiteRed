#include <iostream>
#include <vector>

/*
@
LeetCode 剑指offer
time: 2022-02-09 20:50:27
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target) {
        int nLen = nums.size();
        if (nLen < 2) {
            return std::vector<int>();
        }
        std::vector<int> ans;
        int lo = 0, hi = nLen - 1;
        while (lo < hi) {
            const int sum = nums[lo] + nums[hi];
            if (sum == target) {
                ans.emplace_back(nums[lo]);
                ans.emplace_back(nums[hi]);
                return ans;
            } else if (sum < target) {
                ++lo;
            } else {
                --hi;
            }
        }
        return ans;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums {2, 7, 11, 15};
    int target = 9;
    auto ans = leetcode_cpp::Solution().twoSum(nums, target);
    std::cout << ans[0] << " " << ans[1] << std::endl;
    return 0;
}