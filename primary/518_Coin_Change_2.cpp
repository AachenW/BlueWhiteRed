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
        int minChange = INT_MAX;
        std::vector<int> cnt;
        for (const auto &coin: coins) {
            cnt[coin] = 1;
            if (coin < minChange) {
                minChange = coin;
            }
        }

        for (int i = 1; i <= amount; ++i) {
            for (const auto &coin: coins) {
                if (0 != cnt[i - coin]) {
                    cnt[i] += cnt[i - coin];
                }
            }
        }
        return cnt[amount - 1];
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> coins{1, 2, 5};
    int amount = 5;
    std::cout << leetcode_cpp::Solution().change(amount, coins) << std::endl;
    return 0;
}