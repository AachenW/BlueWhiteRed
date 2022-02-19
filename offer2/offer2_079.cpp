#include <iostream>
#include <vector>
#include <queue>
/*
@
LeetCode 剑指offerⅡ
time: 2022-01-27 21:19:35
author: edinw
@
*/

/*
**  注意：本题与主站 78 题相同： https://leetcode-cn.com/problems/subsets/
** 
**  Given an integer array nums of unique elements, return all possible subsets (the power set).
**  The solution set must not contain duplicate subsets. Return the solution in any order.
*/

namespace leetcode_cpp {
class Solution {
public:
    std::vector<std::vector<int>> subsets(std::vector<int> &nums) {
        backtrack(nums, 0);
        return ans;
    }

private:
    void backtrack(const std::vector<int> &nums, int cur) {
        if (cur == nums.size()) {
            ans.emplace_back(t);
            return;
        }
        t.emplace_back(nums[cur]);
        backtrack(nums, cur + 1);
        t.pop_back();
        backtrack(nums, cur + 1);
    }

private:
    std::vector<int> t;
    std::vector<std::vector<int>> ans;
};

class Solution2{
public:
    std::vector<std::vector<int>> subsets(std::vector<int> &nums) {
        int n = nums.size();
        for (int mask = 0; mask < (1 << n); ++mask) {
            t.clear();
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    t.emplace_back(nums[i]);
                }
            }
            ans.emplace_back(t);
        }
        return ans;
    }

private:
    std::vector<int> t;
    std::vector<std::vector<int>> ans;
};
}

int main(int argc, char **argv) {
    std::vector<int> nums{1, 2, 3};
    auto ans = leetcode_cpp::Solution2().subsets(nums);
    for (const auto &subSet: ans) {
        std::cout << "[";
        for (const auto &num: subSet) {
            std::cout << num << ",";
        }
        std::cout << "]" << std::endl;
    }
    return 0;
}