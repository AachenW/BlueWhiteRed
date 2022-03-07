#include <vector>
#include <iostream>
#include <functional>
#include <unordered_map>
/*
@
LeetCode 剑指offerII
time: 2022-03-04 17:25:44
author: edinw
@
*/

/*
** Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
*/

namespace leetcode_cpp {
class Solution {
public:
    int subarraySum(std::vector<int> &nums, int k) {
        int nSize = nums.size();
        std::unordered_map<int, int> hashMap;
        hashMap[0] = 1;
        int count = 0, prefix = 0;
        
        for (int i = 0; i < nSize; ++i) {
            prefix += nums[i];
            if (hashMap.count(prefix - k)) {
                count += hashMap[prefix - k];
            }
            ++hashMap[prefix];
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
