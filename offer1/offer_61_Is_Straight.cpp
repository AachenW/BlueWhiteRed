#include <iostream>
#include <vector>
#include <unordered_set>

/*
@
LeetCode 剑指offer
time: 2022-02-12 22:18:41
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    bool isStraight(std::vector<int> &nums) {
        std::unordered_set<int> repeat;
        int maxNum = 0, minNum = 14;

        for (const auto &num: nums) {
            if (0 == num) {     
                continue;                       // 跳过大小王
            }
            maxNum = std::max(maxNum, num);     // 更新最大牌
            minNum = std::min(minNum, num);     // 更新最小牌

            if (repeat.count(num)) {
                return false;                   // 若有重复的牌，直接返回false
            }
            repeat.insert(num);                 // 添加牌到set中
        }

        return maxNum - minNum < 5;             // 最大牌 - 最小牌 < 5 则可构成顺子
    }
};

class Solution2 {
    bool isStraight(std::vector<int> &nums) {
        int joker = 0;
        std::sort(nums.begin(), nums.end());
        for (int i = 0; i < 4; ++i) {
            if (0 == nums[i]) {
                ++joker;
            } else if (nums[i] == nums[i + 1]) {
                return false;
            }
        }
        return nums[4] - nums[joker] < 5;
    }
};
}


int main(int argc, char **argv) {
    std::vector<int> nums{0,0,1,2,5};
    std::cout << std::boolalpha << leetcode_cpp::Solution().isStraight(nums) << std::endl;
    return 0;
}