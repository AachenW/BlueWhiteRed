#include <bits/stdc++.h>

/*
@
LeetCode 
time: 2022-03-24 11:22:37
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while (n > 0) {
            n &= (n - 1);
            ++cnt;
        }
        return cnt;
    }
};
}

int main(int argc, char **argv) {
    uint32_t n = 00000000000000000000000000001011;

    std::cout << leetcode_cpp::Solution().hammingWeight(n) << std::endl;

    return 0;
}