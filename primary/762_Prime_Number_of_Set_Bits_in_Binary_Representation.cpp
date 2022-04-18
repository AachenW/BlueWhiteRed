#include <bits/stdc++.h>

/*
@
LeetCode
time: 2022-04-05 20:44:00
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int ans = 0;
        auto count = [] (int n) {
            int ret = 0;
            while (n > 0) {
                n &= n - 1;
                ++ret;
            }
            return ret;
        };

        auto isPrime = [] (int n) -> int {
            int upper = std::sqrt(n) + 1;
            if (2 == n) {
                return 1;
            }
            if (1 == n || 0 == n % 2) {
                return 0;
            }

            for (int i = 3; i <= upper; ++i) {
                if (0 == n % i) {
                    return 0;
                }
            }

            return 1;
        };

        int cnt = 0;
        for (int i = left; i <= right; ++i) {
            ans += isPrime(count(i));
        }

        return ans;
    }
};
}