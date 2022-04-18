#include <bits/stdc++.h>

/*
@
projetc: leetcode
time: 2022-03-31 16:52:02
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int countPrimes(int n) {
        std::vector<int> prime(n, 1);
        int ans = 0;
        for (int i = 2; i < n; ++i) {
            if (prime[i]) {
                ans += 1;
                if ((long long)i * i < n) {
                    for (int j = i * i; j < n; j += i) {
                        prime[j] = 0;
                    }
                }
            }
        }

        return ans;
    }
};
}