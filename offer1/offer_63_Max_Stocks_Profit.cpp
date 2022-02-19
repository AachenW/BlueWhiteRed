#include <iostream>
#include <vector>
#include "limits.h"
/*
@
Leetcode 剑指Offer
time: 2021-12-06 21:31:25
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int maxProfit(std::vector<int> &prices) {
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
    std::vector<int> prices{7, 6, 4, 3, 1};
    std::cout << leetcode_cpp::Solution().maxProfit(prices) << std::endl;
    return 0;
}