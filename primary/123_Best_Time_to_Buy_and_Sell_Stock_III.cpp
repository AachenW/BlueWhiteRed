#include <vector>
#include <string>
#include <iostream>
#include <deque>
#include "limits.h"

/*
@
LeetCode
time: 2022-02-28 15:48:48
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int maxProfit(std::vector<int> &prices) {
        int pSize = prices.size();
        int buy1 = -prices[0];  // 只进行过一次买操作
        int sell1 = 0;          // 进行了一次买操作和一次卖操作，即完成了一笔交易
        int buy2 = -prices[0];  // 在完成了一笔交易的前提下，进行了第二次买操作
        int sell2 = 0;          // 完成了全部两笔交易

        for (int i = 1; i < pSize; ++i) {
            buy1 = std::max(buy1, -prices[i]);
            sell1 = std::max(sell1, buy1 + prices[i]);
            buy2 = std::max(buy2, sell1 - prices[i]);
            sell2 = std::max(sell2, buy2 + prices[i]);
        }

        return sell2;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> prices {3, 3, 5, 0, 0, 3, 1, 4};

    std::cout << leetcode_cpp::Solution().maxProfit(prices) << std::endl;

    return 0;
}