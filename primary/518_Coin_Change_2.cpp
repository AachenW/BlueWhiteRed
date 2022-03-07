#include <vector>
#include <string>
#include <iostream>
#include <deque>
#include <limits.h>

/*
@
leetcode主站
time: 2022-01-29 08:48:06
author: edinw
@
*/

/*
**  You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
**  Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.
**  You may assume that you have an infinite number of each kind of coin.
**  The answer is guaranteed to fit into a signed 32-bit integer.
*/


namespace leetcode_cpp {
class Solution {
public:
    int change(int amount, std::vector<int> &coins) {
        // dp[x] 表示金额之和等于 x 的硬币组合数
        std::vector<int> dp(amount + 1);
        dp[0] = 1;

        // 因为外层循环是遍历数组 coins 的值，内层循环是遍历不同的金额之和，在计算 dp[i] 的值时，可以确保金额之和等于i的硬币面额的顺序，由于顺序确定，因此不会重复计算不同的排列。
        for (const int coin: coins) {
            for (int i = coin; i <= amount; ++i) {
                dp[i] += dp[i - coin];
            }
        }

        return dp[amount];
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> coins{1, 2, 5};
    int amount = 5;
    std::cout << leetcode_cpp::Solution().change(amount, coins) << std::endl;
    return 0;
}