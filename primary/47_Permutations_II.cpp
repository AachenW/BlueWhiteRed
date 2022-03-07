#include <iostream>
#include <vector>
#include <deque>
#include <functional>
#include "limits.h"
#include <unordered_set>
/*
@
Leetcode
time: 2022-03-03 15:46:34
author: edinw
@
*/

namespace leetcode_cpp
{
class Solution {
public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int> &nums) {
        int nSize = nums.size();
        if (0 == nSize) {
            return {};
        }

        std::vector<int> visited;
        std::vector<int> candidates;
        std::vector<std::vector<int>> ans;
        std::function<void(int)> backtrack = [&](int idx) {
            if (idx == nSize) {
                ans.emplace_back(candidates);
                return;
            }

            int prev = INT_MIN;
            for (int i = 0; i < nSize; ++i) {
                // 保证相同的数字都相邻，然后每次填入的数一定是这个数所在重复数集合中「从左往右第一个未被填过的数字」
                if (visited[i] || (i > 0 && nums[i] == nums[i - 1] && !visited[i - 1])) {
                    continue;
                }
                prev = nums[i];
                candidates.emplace_back(nums[i]);
                visited[i] = 1;
                backtrack(idx + 1);
                candidates.pop_back();
                visited[i] = 0;
            }
        };

        backtrack(0);
        return ans;
    }
};

class Solution2 {
private:
    void helper(std::vector<int>& nums, int index, std::vector<std::vector<int>>& ret) {
        if (index == nums.size()) {
            ret.emplace_back(nums);
            return;
        }
        std::unordered_set<int> st;
        for (int i = index; i < nums.size(); ++i) {
            if (!st.count(nums[i])) {
                st.insert(nums[i]);
                std::swap(nums[index], nums[i]);
                helper(nums, index + 1, ret);
                std::swap(nums[index], nums[i]);
            }
        }
    }

public:
    std::vector<std::vector<int>> permuteUnique(std::vector<int>& nums) {
        std::vector<std::vector<int>> ret;
        helper(nums, 0, ret);
        return ret;
    }
};
} // namespace leetcode_cpp

int main(int argc, char **argv) {
    std::vector<int> nums {1,1,2};
    auto ans_vec = leetcode_cpp::Solution().permuteUnique(nums);
    for (const auto &ans : ans_vec) {
        for (const auto &i : ans) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}