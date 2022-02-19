#include <vector>
#include <string>
#include <iostream>
#include <deque>
#include "limits.h"

/*
@
LeetCode 热题 HOT 100
time: 2022-02-05 23:54:11
author: edinw
@
*/

/*
**  You are given an array prices where prices[i] is the price of a given stock on the ith day.
**  You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.
**  Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.
*/

namespace leetcode_cpp {
class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int maxProfit = 0, minPrice = INT_MAX;
        for (const auto &price: prices) {
            maxProfit = std::max(maxProfit, price - minPrice);      // 最大利润 为 历史最低点买入， 再计算当前卖出得到的股票利润，并保存更新后的最大利润
            minPrice = std::min(minPrice, price);                   // 记录股价历史最低点
        }
        return maxProfit;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums {7, 1, 5, 3, 6, 4};
    std::cout << leetcode_cpp::Solution().maxProfit(nums) << std::endl;
    return 0;
}