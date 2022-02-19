#include <iostream>
#include <deque>
#include <vector>
#include <unordered_set>
/*
@
LeetCode 剑指offerⅡ
time: 2022-01-20 20:39:25
author: edinw
@
*/

/*
**  注意：本题与主站 220 题相同： https://leetcode-cn.com/problems/contains-duplicate-iii/
** 
**  给你一个整数数组 nums 和两个整数 k 和 t 。请你判断是否存在 两个不同下标 i 和 j，使得 abs(nums[i] - nums[j]) <= t ，同时又满足 abs(i - j) <= k 。
**  如果存在则返回 true，不存在返回 false。
*/

namespace leetcode_cpp {
class Solution {
public:
    bool containsNearbyAlmostDuplicate(std::vector<int> &nums, int k, int t) {
        int nLength = nums.size();
        int left = 0;
        for (int right = 1; right < nLength; ++right) {
            if (right - left > k) {
                while (abs(nums[++left] - nums[right]) > t && left < right) {
                }
                if (left != right) {
                    return true;
                }
            }
            if (abs(nums[left] - nums[right]) <= t) {
                return true;
            }
        }
        return false;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums {1,5,9,1,5,9};
    int k = 2, t = 3;   
    std::cout << std::boolalpha << leetcode_cpp::Solution().containsNearbyAlmostDuplicate(nums, k, t) << std::endl;
    return 0;
}