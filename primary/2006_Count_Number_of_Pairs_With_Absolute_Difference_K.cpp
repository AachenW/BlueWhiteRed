#include <iostream>
#include <vector>
#include <unordered_map>
/*
@
project: Leetcode
time: 2022-02-09 20:14:02
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int countKDifference(std::vector<int> &nums, int k) {
        int cnt = 0;
        int nLen = nums.size();
        for (int i = 0; i < nLen; ++i) {
            for (int j = i + 1; j < nLen; ++j) {
                if (nums[j] == k + nums[i] || nums[j] == nums[i] - k) {
                    ++cnt;
                }
            }
        }
        return cnt;
    }
};

class Solution2 {
public:
    int countKDifference(std::vector<int> &nums, int k) {
        int cnt = 0, nLen = nums.size();
        std::unordered_map<int, int> cntMap;
        for (int i = 0; i < nLen; ++i) {
            cnt += cntMap.count(nums[i] - k) ? cntMap[nums[i] - k] : 0;
            cnt += cntMap.count(nums[i] + k) ? cntMap[nums[i] + k] : 0;
            ++cntMap[nums[i]];
        }
        return cnt;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums {3,2,1,5,4};
    int k = 2;
    std::cout << leetcode_cpp::Solution().countKDifference(nums, k) << std::endl;
    return 0;
}