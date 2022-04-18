#include <vector>
#include <string>
#include "limits.h"
#include <iostream>
/*
@
LeetCode
time: 2022-03-20 10:15:54
author: edinw
@
*/

namespace leetcode_cpp{
class Solution {
public:
    int reverse(int x) {
        int result = 0;

        while (x) {
            int tail = x % 10;
            int newResult = result * 10 + tail;
            if ((newResult - tail) / 10 != result) {
                return 0;
            }
            result = newResult;
            x /= 10;
        }
        return result;
    }
};

class Solution {
public:
    int reverse(int x) {
        int bit = 0;
        int ans = 0;
        while (x) {
            bit = x % 10;
            if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && bit > 7)) {
                return 0;
            } else if (ans < INT_MIN / 10 || (ans == INT_MIN / 10 && bit > 8)) {
                return 0;
            }
            ans = ans * 10 + bit;
            x /= 10;
        }

        return ans;
    }
};
} // namespace leetcode_cpp
