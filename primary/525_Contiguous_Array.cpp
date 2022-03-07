#include <vector>
#include <iostream>
#include <functional>
#include <unordered_map>
/*
@
LeetCode 剑指offerII
time: 2022-03-04 17:49:31
author: edinw
@
*/

/*
**  Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.
*/

namespace leetcode_cpp {
class Solution {
public:
    int findMaxLength(std::vector<int> &nums) {
        int nSize = nums.size();
        std::unordered_map<int, int> hashMap;   // 哈希表的key是前缀和，但是值存储的是最小的i,即若有多个相同的前缀和只存最小的i，因为这样可以保证求得是最长连续子数组的长度
        int sum = 0, ret = 0;
        hashMap[0] = -1;    // 前缀和为0时存储的索引应该是-1，代表空的连续子数组
        for (int i = 0; i < nSize; ++i) {
            sum += (0 == nums[i]) ? -1 : 1;
            if (hashMap.count(sum)) {
                ret = std::max(ret, i - hashMap[sum]);
            } else {
                hashMap[sum] = i;
            }
        }

        return ret;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums{0, 1, 0};
    
    std::cout << leetcode_cpp::Solution().findMaxLength(nums) << std::endl;

    return 0;
}
