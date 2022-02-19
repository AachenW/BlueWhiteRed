#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
/*
@
project: Leetcode
time: 2022-01-25 19:25:45
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int numberOfMatches(int n) {
        int count = 0;
        while (n > 1) {
            if (n & 1) {
                n = (n - 1) / 2;
                count += n;
                n += 1;
            } else {
                n /= 2;
                count += n;
            }
        }
        return count;
    }
};
}

int main(int argc, char **argv) {
    int n = 14;
    std::cout << leetcode_cpp::Solution().numberOfMatches(n) << std::endl;
    return 0;
}