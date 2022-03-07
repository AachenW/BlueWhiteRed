#include <vector>
#include <iostream>
#include <unordered_set>
#include <queue>
/*
@
LeetCode
time: 2022-03-03 17:29:02
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int addDigit(int num) {
        while (num / 10 != 0) {
            int tmp = 0;
            while (num) {
                tmp += num % 10;
                num /= 10;
            }
            num = tmp;
        }
        return num;
    }
};
}

int main(int argc, char **argv) {
    int num = 38;
    
    std::cout << leetcode_cpp::Solution().addDigit(num) << std::endl;

    return 0;
}