#include <vector>
#include <string>
#include <iostream>
#include <deque>
#include "limits.h"

/*
@
LeetCode
time: 2022-03-17 14:44:25
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int pSize = prices.size(), maxPro = 0;
        if (1 == pSize) {
            return 0;
        }

        for (int i = 0; i < pSize - 1; ++i) {
            if (prices[i + 1] > prices[i]) {
                maxPro += prices[i + 1] - prices[i];
            }
        }

        return maxPro;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums {7, 1, 5, 3, 6, 4};
    std::cout << leetcode_cpp::Solution().maxProfit(nums) << std::endl;
    return 0;
}