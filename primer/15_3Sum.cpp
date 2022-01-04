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
time: 2021-12-12 22:58:54
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    std::vector<std::vector<int>> threeSum(std::vector<int>& nums) {
        int nLength = nums.size();
        if (nLength < 3) {
            return {};
        }
        sort(nums.begin(), nums.end());
        std::vector<std::vector<int>> ans;
        // 枚举a
        for (int first = 0; first < nLength; ++first) {
            // 需要和上一次枚举的数不相同
            if (first > 0 && nums[first] == nums[first - 1]) {
                continue;
            }
            // c对应的指针初始值指向数组的最右端
            int third = nLength - 1;
            int target = -nums[first];
            // 枚举b
            for (int second = first + 1; second < nLength; ++second) {
                // 需要和上一次枚举的数不相同
                if (second > first + 1 && nums[second] == nums[second - 1]) {
                    continue;
                }
                // 需要保证b的指针在c的指针的左侧
                while (second < third && nums[second] + nums[third] < target) {
                    --third;
                }
                // 如果指针重合，随着b后续的增加就不会有满足a+b+c = 0 并且b < c的c了，此刻退出循环
                if (second == third) {
                    break;
                }
                if (nums[second] + nums[third] == target) {
                    ans.push_back({nums[first], nums[second], nums[third]});
                }
            }
        }

        return ans; 
    }
};
}

int main(int argc, char** argv) {
    std::vector<int> nums {-1,0,1,2,-1,-4};
    std::vector<std::vector<int>> ans = leetcode_cpp::Solution().threeSum(nums);
    for (auto outputs : ans) {
        for (int output : outputs) {
            std::cout << output << " ";
        }
        std::cout << std::endl;
    }
}