#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <ctime>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cstdlib>
#include <numeric>
#include <limits.h>

/*
@
LeetCode 剑指offerⅡ
time: 2021-12-20 21:01:57
author: edinw
@
*/
namespace leetcode_cpp{
class Solution {
public:
    int divide(int a, int b) {
        if (a == 0) {
            return 0;
        }
        if (b == 1) {
            return a;
        }
        if (b == -1) {
            if (a > INT_MIN) {
                return -a;
            } else {
                return INT_MAX;
            }
        }

        long dividend = a;
        long divisor = b;
        int sign = 1;
        if ((dividend >  0 && divisor < 0) || (dividend < 0 && divisor > 0)) {
            sign = -1;
        } 
        dividend = dividend > 0 ? dividend : -dividend;
        divisor = divisor > 0 ? divisor : -divisor;
        long res = div(dividend, divisor);
        if (sign > 0) {
            return res > INT_MAX ? INT_MAX : res;
        }
        return -res;
    }

private:
    int div(long a, long b) {
        if (a < b) {
            return 0 ;
        }
        long count = 1;
        long tb = b;
        while ((tb + tb) <= a) {
            count = count + count;
            tb = tb + tb;
        }
        return count + div(a - tb, b);
    }
};
}

int main(int argc, char **argv) {
    std::cout << leetcode_cpp::Solution().divide(-2147483648, 2) << std::endl;

    return 0;
}