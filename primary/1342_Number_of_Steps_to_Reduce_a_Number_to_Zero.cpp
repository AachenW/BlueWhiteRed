#include <vector>
#include <iostream>

/*
@
project: Leetcode
time: 2022-01-31 09:04:42
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int numberOfSteps(int num) {
        int cnt = 0;
        while (num > 0) {
            if (num & 1) {
                num -= 1;
            } else {
                num >>= 1;
            }
            ++cnt;
        }
        return cnt;
    }
};

class Solution2 {
public:
    int numberOfSteps(int num) {
        // 二进制数长度 len 可以通过前导零数目 clz 间接求解，即 len = W − clz，其中 W = 32 是 int 类型的位数。
        return num ? 31 - __builtin_clz(num) + __builtin_popcount(num) : 0;
    }
};
}

int main(int argc, char **argv) {
    int num = 14;
    std::cout << leetcode_cpp::Solution().numberOfSteps(num) << std::endl;
    return 0;
}