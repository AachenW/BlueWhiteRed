#include <vector>
#include <functional>

/*
@
project: leetcode
time: 2022-03-09 20:10:53
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
    static constexpr int MOD = 1000000007;
public:
    int knigthDialer(int n) {
        std::vector<std::vector<int>> moves = {{4, 6}, {6, 8}, {7, 9}, {4, 8}, {3, 9, 0}, {}, {1, 7, 0}, {2, 6}, {1, 3}, {4, 2}};;
        std::vector<std::vector<int>> memo(n, std::vector<int>(10, 0));
        
        std::function<int(int, int)> backtrack = [&](int n, int num) {
            if (0 == n) {
                return 1;
            }
            if (0 != memo[n][num]) {
                return memo[n][num];
            }

            int res = 0;
            for (auto &&neighbor: moves[num]) {
                res = (res + backtrack(n - 1, neighbor)) % MOD;
            }
            memo[n][num] = res;

            return memo[n][num];
        };

        int res = 0;

        for (int i = 0; i < 10; ++i) {
            res = (res + backtrack(n - 1, i)) % MOD;
        }
    }
};

class Solution2 {
    static constexpr int MOD = 1000000007;
public:
    int knigthDialer(int n) {
        std::vector<std::vector<int>> moves = {{4, 6}, {6, 8}, {7, 9}, {4, 8}, {3, 9, 0}, {}, {1, 7, 0}, {2, 6}, {1, 3}, {4, 2}};
        std::vector<std::vector<int>> dp(n, std::vector<int>(10, 0));

        for (int i = 0; i < 10; ++i) {
            dp[0][i] = 1;
        }

        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < 10; ++j) {
                for (int arrive: moves[j]) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][arrive]) % MOD;
                }
            }
        }

        int res = 0;
        for (int num = 0; num < 10; num++)
            res = (res + dp[n - 1][num]) % MOD;
        return res;
    }
};
}