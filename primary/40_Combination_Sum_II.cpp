#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>

/*
@
LeetCode
time: 2022-02-25 23:03:48
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int> &candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        int nSize = candidates.size();
        std::vector<std::vector<int>> ans;
        std::vector<int> combination;
        std::function<void(int, int)> backtrack = [&](int start, int sum) {
            if (sum == target) {
                ans.emplace_back(combination);
                return;
            }

            for (int i = start; i < nSize; ++i) {
                if (i > start && candidates[i] == candidates[i - 1]) {
                    continue;
                }
                int num = sum + candidates[i];
                if (num <= target) {
                    combination.emplace_back(candidates[i]);
                    backtrack(i + 1, num);
                    combination.pop_back();
                } else {
                    break;
                }
            }
        };

        backtrack(0, 0);

        return ans;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums{10, 1, 2, 7, 6, 1, 5};
    int target = 8;

    auto ans = leetcode_cpp::Solution().combinationSum2(nums, target);

    for (const auto &num: ans) {
        for (const int output: num) {
            std::cout << output << ",";
        }
        std::cout << std::endl;
    }

    return 0;
}