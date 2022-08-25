#include <bits/stdc++.h>

namespace leetcode_cpp {
class Solution {
public:
    int maxProfit(std::vector<int> &prices, int fee) {
        int pSize = prices.size();
        std::vector<std::vector<int>> dp(pSize, std::vector<int>(2));

        dp[0][0] = 0;
        dp[0][1] = -prices[0];

        for (int i = 1; i < pSize; ++i) {
            dp[i][0] = std::max(dp[i - 1][0], dp[i - 1][1] + prices[i] - fee);
            dp[i][1] = std::max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
        }

        return dp[pSize - 1][0];
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> prices{1, 3, 2, 8, 4, 9};
    int fee = 2;

    std::cout << leetcode_cpp::Solution().maxProfit(prices, fee) << '\n';

    return 0;
}
