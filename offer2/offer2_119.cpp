#include <vector>
#include <iostream>
#include <deque>
#include "limits.h"
#include <unordered_set>
#include <queue>
#include <algorithm>
/*
@
LeetCode 剑指offerⅡ
time: 2022-01-19 21:54:20
author: edinw
@
*/

/*
** 注意：本题与主站 128 题相同： https://leetcode-cn.com/problems/longest-consecutive-sequence/
**
** 给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
*/


namespace leetcode_cpp {
class Solution {
public:
    int longestConsecutive(std::vector<int> &nums) {
        std::unordered_set<int> hashMap;
        for (const int& num: nums) {
            hashMap.insert(num);
        }

        int maxLength = 0;
        for (const int &num: hashMap) {
            if (!hashMap.count(num - 1)) {
                int curNum = num;
                int curStreak = 1;

                while (hashMap.count(curNum + 1)) {
                    ++curStreak;
                    ++curNum;
                }

                maxLength = std::max(maxLength, curStreak);
            }
        }

        return maxLength;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums {0,3,7,2,5,8,4,6,0,1};
    std::cout << leetcode_cpp::Solution().longestConsecutive(nums) << std::endl;
    return 0;
}