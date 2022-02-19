#include <iostream>

/*
@
LeetCode 剑指offer
time: 2022-02-01 15:09:31
author: edinw
@
*/

/*
**  注意：本题与主站 154 题相同：https://leetcode-cn.com/problems/find-minimum-in-rotated-sorted-array-ii/
** 
**  Write a function that takes an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).
**
**  Note:
**      Note that in some languages, such as Java, there is no unsigned integer type. In this case, the input will be given as a signed integer type. It **         should not affect your implementation, as the integer's internal binary representation is the same, whether it is signed or unsigned.
**      In Java, the compiler represents the signed integers using 2's complement notation. Therefore, in Example 3, the input represents the signed 
**         integer. -3.
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
    uint32_t n = 0b00000000000000000000000000001011;
    std::cout << leetcode_cpp::Solution().hammingWeight(n) << std::endl;
    return 0;
}