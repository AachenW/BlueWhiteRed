#include <iostream>
#include <vector>

/*
@
LeetCode 剑指offer
time: 2022-02-18 22:15:16
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    std::vector<std::vector<int>> findContinuousSequence(int target) {
        int left = 1, right = 2, end = (target + 1) / 2;
        std::vector<std::vector<int>> ans;
        std::vector<int> tmp;
        int sum = left + right;
        int idx = 0;

        auto insert = [] (std::vector<int> &nums, int lo, int hi) {
            for (int i = lo; i <= hi; ++i) {
                nums.emplace_back(i);
            }
        };

        while (left < end) {
            if (sum == target) {
                insert(tmp, left, right);
                ans.emplace_back(tmp);
                tmp.clear();
            }

            while (sum > target && left < end) {
                sum -= left;
                ++left;
                if(sum == target) {
                    insert(tmp, left, right);
                    ans.emplace_back(tmp);
                    tmp.clear();
                }
            }
            ++right;
            sum += right;
        }

        return ans;
    }

};
}

int main(int argc, char **argv) {
    int target = 9;
    auto ans = leetcode_cpp::Solution().findContinuousSequence(target);
    for (const auto &nums: ans) {
        for (const auto &num: nums) {
            std::cout << num << ", ";
        }
        std::cout << std::endl;
    }
    return 0;
}