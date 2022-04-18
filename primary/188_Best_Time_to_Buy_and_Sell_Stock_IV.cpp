#include <bits/stdc++.h>

namespace leetcode_cpp {
class Solution {
public:
    int maxProfit(int k, std::vector<int>& prices) {
        if (prices.empty()) {
            return 0;
        }

        int n = prices.size();
        k = std::min(k, n >> 1);    // n 天最多只能进行 ⌊n/2⌋ 笔交易，因此我们可以将 k 对  取较小值之后再进行动态规划。

        // 对于数组 prices[0..i] 中的价格而言，进行恰好 j 笔交易，并且当前手上持有一支股票，这种情况下的最大利润。
        std::vector<std::vector<int>> buy(n, std::vector<int>(k + 1));
        // 用 sell[i][j] 表示恰好进行 j 笔交易，并且当前手上不持有股票，这种情况下的最大利润。
        std::vector<std::vector<int>> sell(n, std::vector<int>(k + 1));

        buy[0][0] = -prices[0]; // 在第 0 天以prices[0]的价格买入股票是唯一满足手上持有股票的方法。
        sell[0][0] = 0; // 对于sell[0][0]，它的值为 0，即「我们在第 0 天不做任何事」是唯一满足手上不持有股票的方法。

        for (int i = 1; i <= k; ++i) {
            buy[0][i] = sell[0][i] = INT_MIN / 2;   // 表示不合法的状态
        }

        for (int i = 1; i < n; ++i) {
            buy[i][0] = std::max(buy[i - 1][0], sell[i - 1][0] - prices[i]);
            for (int j = 1; j <= k; ++j) {
                buy[i][j] = std::max(buy[i - 1][j], sell[i - 1][j] - prices[i]);
                sell[i][j] = std::max(buy[i - 1][j - 1] + prices[i], sell[i - 1][j]);
            }
        }

        return *std::max_element(sell[n - 1].begin(), sell[n - 1].end());
    }

};
}