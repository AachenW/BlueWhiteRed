#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
/*
@
projetc: leetcode
time: 2022-03-03 17:22:50
author: edinw
@
*/

namespace leetcode_cpp{
class Solution {
public:
    int coinChange(std::vector<int> &coins, int amount) {
        std::vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;

        for (int i = 1; i <= amount; ++i) {
            for (const int coin: coins) {
                if (coin <= i) {
                    dp[i] = std::min(dp[i], dp[i - coin] + 1);
                }
            }
        }

        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};
} // namespace leetcode_cpp

int main(int argc, char **argv) {
    std::vector<int> coins {1, 2 ,5};
    int target = 11;

    std::cout << leetcode_cpp::Solution().coinChange(coins, target) << std::endl;

    return 0;
}

