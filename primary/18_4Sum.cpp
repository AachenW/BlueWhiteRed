#include <vector>
#include <iostream>
#include <algorithm>
/*
@
LeetCode
time: 2022-02-25 22:07:37
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    std::vector<std::vector<int>> fourSum(std::vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());
        int nSize = nums.size();
        std::vector<std::vector<int>> ans;

        for (int first = 0; first < nSize; ++first) {
            if (first > 0 && nums[first] == nums[first - 1]) {
                continue;
            }
            for (int second = first + 1; second < nSize; ++second) {
                if (second > first + 1 && nums[second] == nums[second - 1]) {
                    continue;
                }
                int forth = nSize - 1;
                int res = target - (nums[first] + nums[second]); 
                for (int third = second + 1; third < nSize; ++third) {
                    if (third > second + 1 && nums[third] == nums[third - 1]) {
                        continue;
                    }

                    while (forth > third && nums[third] + nums[forth] > res) {
                        --forth;
                    }

                    if (third == forth) {
                        break;
                    }
                    if (nums[third] + nums[forth] == res) {
                        ans.push_back({nums[first], nums[second], nums[third], nums[forth]});
                    }
                }
            }
        }

        return ans;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums{2, 2, 2, 2, 2};
    int target = 8;
    
    auto ans = leetcode_cpp::Solution().fourSum(nums, target);

    for (const auto &nums: ans) {
        for (const int num: nums) {
            std::cout << num << ",";
        }
        std::cout << std::endl;
    }

    return 0;
}