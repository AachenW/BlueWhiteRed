#include <vector>
#include <unordered_map>
#include <iostream>
/*
@
LeetCode 剑指offerⅡ
time: 2021-12-26 17:16:39
author: edinw
@
*/

/*
// 本题与主站 560 题相同： https://leetcode-cn.com/problems/subarray-sum-equals-k/
// 给定一个整数数组和一个整数 k ，请找到该数组中和为 k 的连续子数组的个数。
*/

namespace leetcode_cpp {
class Solution{
public:
    int subarraySum(std::vector<int> &nums, int k) {
        std::unordered_map<int, int> mp;
        mp[0] = 1;
        int count = 0, pre = 0;
        for (auto &num : nums) {
            pre += num;
            if (mp.find(pre - k) != mp.end()) {
                count += mp[pre - k];
            }
            mp[pre]++;
        }        
        return count;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums{1, 1, 1};
    int k = 2;
    std::cout << leetcode_cpp::Solution().subarraySum(nums, k) << std::endl;
    return 0;
}