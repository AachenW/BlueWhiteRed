#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <ctime>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cstdlib>
#include <numeric>

/*
@
LeetCode 精选 TOP 面试题
time: 2021-12-09 20:58:30
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    // 时间复杂度为O(N), 空间复杂度为O(N);
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        int nLength = nums.size();
        std::unordered_map<int, int> hashTable;
        for (int i = 0; i < nLength; ++i) {
            auto it = hashTable.find(target - nums[i]);
            if (it != hashTable.end()) {
                return {it->second, i};
            }
            hashTable[nums[i]] = i;
        }
        return {};
    }
};
}

int main(int argc, char** argv) {
    std::vector<int> nums{2, 7, 11, 15};
    int target = 9;
    std::vector<int> ans = leetcode_cpp::Solution().twoSum(nums, target);
    for (auto output: ans) {
        std::cout << output << " "; 
    }
}