#include <unordered_map>
#include <vector>
#include <iostream>
/*
@
LeetCode 剑指offerⅡ
time: 2021-12-20 21:08:48
author: edinw
@
*/

// 给你一个整数数组 nums ，除某个元素仅出现 一次 外，其余每个元素都恰出现 三次 。请你找出并返回那个只出现了一次的元素。

namespace leetcode_cpp {
class Solution{
public:
    int singleNumber(std::vector<int> &nums) {
        std::unordered_map<int, int> freq;
        for (const int &i : nums) {
            ++freq[i];
        }
        int ans = 0;
        for (const auto &item : freq) {
            if (item.second == 1) {
                ans = item.first;
                break;
            }
        }

        return ans;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums {0,1,0,1,0,1,100};
    std::cout << leetcode_cpp::Solution().singleNumber(nums) << std::endl;
    return 0;
}