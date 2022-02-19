#include <iostream>
#include <vector>
#include <string>
#include "limits.h"
/*
@
LeetCode 剑指offerⅡ
time: 2022-01-24 21:35:49
author: edinw
@
*/

/*
**  注意：本题与主站 69 题相同： https://leetcode-cn.com/problems/sqrtx/
** 
**  Given a non-negative integer x, compute and return the square root of x.
**  Since the return type is an integer, the decimal digits are truncated, and only the integer part of the result is returned.
**  Note: You are not allowed to use any built-in exponent function or operator, such as pow(x, 0.5) or x ** 0.5.
*/

namespace leetcode_cpp {
class Solution {
public:
    int mySqrt(int x) {
        int left = 1, right = x;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (mid <= x / mid) {
                if (mid + 1 > x / (mid + 1)) {
                    return mid;
                }
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return 0;
    }
};
}

int main(int argc, char **argv) {
    int x = 8;
    std::cout << leetcode_cpp::Solution().mySqrt(x) << std::endl;
    return 0;
}