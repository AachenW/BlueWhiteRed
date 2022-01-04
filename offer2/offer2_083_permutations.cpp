#include <vector>
#include <iostream>
/*
@
LeetCode 剑指offerⅡ
time: 2021-12-21 20:42:52
author: edinw
@
*/

// 给定一个不含重复数字的整数数组 nums ，返回其 所有可能的全排列 。可以 按任意顺序 返回答案。

namespace leetcode_cpp {
class Solution{
public:
    std::vector<std::vector<int>> permute(std::vector<int> &nums) {
        decltype(nums.size()) nLength = nums.size();
        if (nLength == 0) {
            return {};
        }
        std::vector<std::vector<int>> ans;
        backtrack(ans, nums, 0, nLength);
        return ans;
    }

private:
    void backtrack(std::vector<std::vector<int>>& res, std::vector<int>& output, int first, int len) 
    {
        // 所有数都填完了
        if (first == len) {
            res.emplace_back(output);
            return;
        }
        for (int i = first; i < len; ++i) {
            
            std::swap(output[i], output[first]);
            backtrack(res, output, first + 1, len);
            std::swap(output[i], output[first]);
        }
        
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums {1,2,3};
    auto ans = leetcode_cpp::Solution().permute(nums);
    for (const auto &num : ans) {
        for (const auto &i : num) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}