#include <iostream>
/*
@
project: Leetcode
time: 2022-01-15 20:24:56
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int totalMoney(int n) {
        if (n < 1) {
            return 0;
        }
        int sum = 0;
        while (n > 7) {
            int weeks = n / 7;
            for (int i = 1; i <8; ++i) {
                sum += i * weeks + 1;
            }
            n -= 7;
        }
        for (int i = 1; i <= 7; ++i) {
            sum += i;
        }
        return sum;
    }
};
}

int main(int argc, char **argv) {
    int n = 4;
    std::cout << leetcode_cpp::Solution().totalMoney(n) << std::endl;
    return 0;
}