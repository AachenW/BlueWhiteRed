#include <iostream>
#include <vector>

/*
@
LeetCode HOT 100
time: 2022-02-03 22:19:41
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int> &candidates, int target) {
        std::vector<std::vector<int>> ans;
        std::vector<int> combine;
        backtrack(candidates, target, ans, combine, 0);
        return ans;
        
    }

private:
    void backtrack(std::vector<int> &candidates, int target, std::vector<std::vector<int>> &ans, std::vector<int> &combine, int idx) {
        if (idx == candidates.size()) {
            return;
        }
        if (0 == target) {
            ans.emplace_back(combine);
            return;
        }
        // 直接跳过
        backtrack(candidates, target, ans, combine, idx + 1);
        // 选择当前数
        if (target - candidates[idx] >= 0) {
            combine.emplace_back(candidates[idx]);
            // 注意到每个数字可以被无限制重复选取，因此搜索的下标仍为 idx
            backtrack(candidates, target - candidates[idx], ans, combine, idx);
            combine.pop_back();
        }
    }
};

class Solution2 {
public:
    // 搜索回溯+剪枝
    std::vector<std::vector<int>> combinationSum(std::vector<int> &candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        std::vector<std::vector<int>> ans;
        std::vector<int> combine;
        backtrack(candidates, combine, ans, target, 0);
        return ans;
    }

private:
    void backtrack(std::vector<int> &candidates, std::vector<int> &combine, std::vector<std::vector<int>> &ans, int target, int idx) {
        if (idx == candidates.size()) {
            return;
        }
        if (0 == target) {
            ans.emplace_back(combine);
            return ;
        }
        // 剪枝
        if (target < 0) {
            return;
        }

        backtrack(candidates, combine, ans, target, idx + 1);
        if (target - candidates[idx] >= 0) {
            combine.emplace_back(candidates[idx]);
            backtrack(candidates, combine, ans, target - candidates[idx], idx);
            combine.pop_back();
        }
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> candidates{2, 3, 6, 7};
    int target = 7;
    auto ans = leetcode_cpp::Solution().combinationSum(candidates, target);
    for (const auto &nums: ans) {
        for (const auto &num: nums) {
            std::cout << num << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}