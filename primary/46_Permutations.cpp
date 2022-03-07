#include <iostream>
#include <vector>
#include <deque>
#include <functional>

/*
@
Leetcode
time: 2022-03-03 15:36:08
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    std::vector<std::vector<int>> permute(std::vector<int> &nums) {
        int nSize = nums.size();
        if (0 == nSize) {
            return {};
        }

        std::vector<std::vector<int>> ans;
        std::function<void(int)> backtrack = [&](int idx) {
            if (idx = nSize) {
                ans.emplace_back(nums);
                return;
            }

            for (int i = idx; i < nSize; ++i) {
                std::swap(nums[idx], nums[i]);
                backtrack(idx + 1);
                std::swap(nums[idx], nums[i]);
            }
        };

        backtrack(0);

        return ans;
    }
};

class Solution2 {
public:
    std::vector<std::vector<int>> permute(std::vector<int>& nums) {
        decltype(nums.size()) nLength = nums.size();
        if (nLength == 0) {
            return {};
        }
        std::vector<std::vector<int>> ans;
        std::vector<int> path;
        std::vector<bool> used(nLength);
        backtrack(nums, nLength, 0, path, ans, used);
        return ans;
    }

private:
    void backtrack(std::vector<int> &nums, int len, int depth, std::vector<int> &path, std::vector<std::vector<int>> &ans, std::vector<bool> &used)
    {
        if (depth == len) {
            ans.emplace_back(path);
            return;
        }

        for (int i = 0; i < len; ++i) {
            if (used[i]) {
                continue;
            }
            path.emplace_back(nums[i]);
            used[i] = true;
            backtrack(nums, len, depth + 1, path, ans, used);
            used[i] = false;
            path.pop_back();
        }
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums{1, 2, 3};
    
    auto ans = leetcode_cpp::Solution().permute(nums);

    for (const auto &nums: ans) {
        for (const int num: nums) {
            std::cout << num << ", ";
        }
    }
    std::cout << std::endl;

    return 0;
}