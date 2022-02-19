#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
/*
@
projetc: leetcode
time: 2022-02-16 22:28:06
author: edinw
@
*/

/*
**  You are given an array prices where prices[i] is the price of a given stock on the ith day.
**  
**  Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple 
**      times) with the following restrictions:
**
**  After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
**  Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
*/

namespace leetcode_cpp {
class Solution {
public:
    int maxProfit(std::vector<int> &prices) {
        int nSize = prices.size();

        // dp[i][0]: 手上持有股票的最大收益
        // dp[i][1]: 手上不持有股票，并且处于冷冻期中的累计最大收益
        // dp[i][2]: 手上不持有股票，并且不在冷冻期中的累计最大收益
        std::vector<std::vector<int>> dp (nSize, std::vector<int>(3, 0));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        dp[0][2] = 0;

        for (int i = 1; i < nSize; ++i) {
            // 对于 f[i][0]，我们目前持有的这一支股票可以是在第 i−1 天就已经持有的，对应的状态为 f[i−1][0]；或者是第 i 天买入的，那么第 i−1 天就不能持有股票并且不处于冷冻期中，对应的状态为 f[i−1][2] 加上买入股票的负收益 prices[i]
            dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][2] - prices[i]);
            // 对于 f[i][1]，我们在第 i 天结束之后处于冷冻期的原因是在当天卖出了股票，那么说明在第 i−1 天时我们必须持有一支股票，对应的状态为 f[i−1][0] 加上卖出股票的正收益 prices[i]。
            dp[i][1] = dp[i - 1][0] + prices[i];
            // 对于 f[i][2]，我们在第 i 天结束之后不持有任何股票并且不处于冷冻期，说明当天没有进行任何操作，即第 i−1 天时不持有任何股票：如果处于冷冻期，对应的状态为 f[i−1][1]；如果不处于冷冻期，对应的状态为 f[i-1][2]
            dp[i][2] = std::max(dp[i - 1][1], dp[i - 1][2]);
        }

        return std::max(dp[nSize - 1][1], dp[nSize - 1][2]);
    }
};

class Solution2 {
public:
    int maxProfit(std::vector<int> &prices) {
        int nSize = prices.size();

        // dp[i][0]: 手上持有股票的最大收益
        // dp[i][1]: 手上不持有股票，并且处于冷冻期中的累计最大收益
        // dp[i][2]: 手上不持有股票，并且不在冷冻期中的累计最大收益
        std::vector<int> dp (3, 0);
        dp[0] = -prices[0];
        
        for (int i = 1; i < nSize; ++i) {
            int new0 = std::max(dp[0], dp[2] - prices[i]);
            int new1 = dp[0] + prices[i];
            int new2 = std::max(dp[1], dp[2]);
            dp[0] = new0;
            dp[1] = new1;
            dp[2] = new2;
        }
        return std::max(dp[1], dp[2]);
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> prices {1, 2, 3, 0, 2};
    std::cout << leetcode_cpp::Solution2().maxProfit(prices) << std::endl;
    return 0;
}