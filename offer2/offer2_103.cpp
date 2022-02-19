#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include "limits.h"
/*
@
LeetCode 剑指offerⅡ
time: 2022-01-13 19:32:39
author: edinw
@
*/

/*
注意：本题与主站 322 题相同： https://leetcode-cn.com/problems/coin-change/

给定不同面额的硬币 coins 和一个总金额 amount。编写一个函数来计算可以凑成总金额所需的最少的硬币个数。如果没有任何一种硬币组合能组成总金额，返回 -1。

你可以认为每种硬币的数量是无限的。
*/

namespace leetcode_cpp {
class Solution {
public:
    int coinChange(std::vector<int> &coins, int amount) {
        if (amount < 1) {
            return 0;
        }
        count.resize(amount);
        return dp(coins, amount);
    }

private:
    int dp(std::vector<int> &coins, int rem) {
        if (rem < 0) {
            return -1;
        }
        if (0 == rem) {
            return 0;
        }
        if (count.at(rem - 1) != 0) {
            return count.at(rem - 1);
        }
        int minNum = INT_MAX;
        for (const int &coin: coins) {
            int res = dp(coins, rem - coin);
            if (res >= 0 && res < minNum) {
                minNum = res + 1;
            }
        }
        count.at(rem - 1) = minNum == INT_MAX ? -1 : minNum;
        return count.at(rem - 1);
    }

private:
    std::vector<int> count;
};

class Solution2 {
public:
    int coinChange(std::vector<int> &coins, int amount) {
        int maxNum = amount + 1;
        auto dp = std::vector<int>(amount + 1, maxNum);
        dp[0] = 0;
        int cSize = coins.size();
        for (int i = 1; i <= amount; ++i) {
            for (int j = 0; j < cSize; ++j) {
                if (coins.at(j) <= i) {
                    dp[i] = std::min(dp[i], dp[i - coins.at(j)] + 1);
                }
            }
        }
        return dp.at(amount);
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> coins {1, 2, 5};
    int amount = 11;
    std::cout << leetcode_cpp::Solution2().coinChange(coins, amount) << std::endl;
    return 0;
}