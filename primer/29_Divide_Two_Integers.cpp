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
LeetCode 精选 TOP 面试题
time: 2021-12-17 21:42:18
author: edinw
@
*/

namespace leetcode_cpp{
class Solution{
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0) {
            return 0;
        }
        if (divisor == 1) {
            return dividend;
        }
        if (divisor == -1) {
            if (dividend > INT_MIN) {
                return -dividend;
            } else {
                return INT_MAX;
            }
        }

        long a = dividend;
        long b = divisor;
        int sign = 1;
        if ((a > 0 && b < 0) || (a < 0 && b > 0)) {
            sign = -1;
        }
        a = a > 0 ? a : -a;
        b = b > 0 ? b : -b;
        long res = div(a, b);
        if (sign > 0) {
            return res > INT_MAX ? INT_MAX : res;
        }
        return -res;
    }

private:
    int div(long a, long b) {
        if (a < b) {
            return 0;
        }
        long count = 1;
        long tb = b;    // 在后面的代码中不更新b
        while ((tb + tb) <= a) {
            count = count + count;  // 最小解翻倍
            tb = tb + tb;   // 当前测试的值也翻倍
        }

        return count + div(a - tb, b);
    }

};
}

int main(int argc, char **argv) {
    std::cout << leetcode_cpp::Solution().divide(-2147483648, 2) << std::endl;

    return 0;
}