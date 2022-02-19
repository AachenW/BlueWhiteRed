#include <string>
#include <vector>
#include <iostream>
#include <numeric>
/*
@
project: leetcode
time: 2022-01-17 20:20:08
author: edinw
@
*/


namespace leetcode_cpp {
class Solution {
public:
    int countVowelPermutation(int n) {
        if (0 == n) {
            return 0;
        }
        long long mod = 1e9 + 7;
        auto dp = std::vector<long long>(5, 1);
        auto ndp = std::vector<long long>(5);
        for (int i = 2; i <=n ; ++i) {
            /* a前面可以为e,u,i */
            ndp.at(0) = (dp.at(1) + dp.at(2) + dp.at(4)) % mod;
            /* e前面可以为a,i */
            ndp.at(1) = (dp.at(0) + dp.at(2)) % mod;
            /* i前面可以为e,o */
            ndp.at(2) = (dp.at(1) + dp.at(3)) % mod;
            /* o前面可以为i */
            ndp.at(3) = dp.at(2) % mod;
            /* u前面可以为i,o */
            ndp.at(4) = (dp.at(2) + dp.at(3)) % mod;
            dp = ndp;            
        }
        return std::accumulate(dp.begin(), dp.end(), 0LL) % mod;
    }
};
}

int main(int argc, char **argv) {
    std::cout << leetcode_cpp::Solution().countVowelPermutation(144) << std::endl;
}