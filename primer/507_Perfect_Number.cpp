#include <vector>
#include <iostream>
/*
@
project: leetcode
time: 2021-12-31 14:59:31
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (1 == num) {
            return false;
        }

        int sum = 1;
        // 只需要枚举不超过sqrt(num)的数
        for (int d = 2; d * d <= num; ++d) {
            if (0 == num % d) {
                sum += d;
                if (d * d < num) {
                    sum += num / d; // 若找到了一个因数d，那么就找到了因数num / d.
                }
            }
        }
        return sum == num;
    }
};
}

int main(int argc, char **argv) {
    int num = 28;
    std::cout << leetcode_cpp::Solution().checkPerfectNumber(num) << std::endl;
    return 0;
}