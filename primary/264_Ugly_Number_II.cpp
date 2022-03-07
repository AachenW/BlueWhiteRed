#include <vector>
#include <iostream>
#include <unordered_set>
#include <queue>
/*
@
LeetCode 剑指offer
time: 2022-02-20 21:40:21
author: edinw
@
*/

/*
**  注意：本题与主站 264 题相同：https://leetcode-cn.com/problems/ugly-number-ii/
**
**  An ugly number is a positive integer whose prime factors are limited to 2, 3, and 5.
**
**  Given an integer n, return the nth ugly number.
*/

namespace leetcode_cpp {
class Solution {
public:
    int nthUglyNumber(int n) {
        std::vector<int> factors {2, 3, 5};
        std::unordered_set<long> seen;
        std::priority_queue<long, std::vector<long>, std::greater<long>> heap;
        seen.insert(1L);
        heap.emplace(1L);
        int ugly = 0;
        for (int i = 0; i < n; ++i) {
            long curr = heap.top();
            heap.pop();
            ugly = (int)curr;
            for (int factor: factors) {
                long next = curr * factor;
                if (!seen.count(next)) {
                    seen.insert(next);
                    heap.emplace(next);
                }
            }
        }

        return ugly;
    }
};

class Solution2 {
public:
    int nthUglyNumber(int n) {
        std::vector<int> dp(n + 1, 0);
        dp[1] = 1;
        int p2 = 1, p3 = 1, p5 = 1;
        for (int i = 2; i < n + 1; ++i) {
            int num2 = dp[p2] * 2, num3 = dp[p3] * 3, num5 = dp[p5] * 5;
            dp[i] = std::min(std::min(num2, num3), num5);
            if (dp[i] == num2) {
                ++p2;
            }
            if (dp[i] == num3) {
                ++p3;
            }
            if (dp[i] == num5) {
                ++p5;
            }
        }
        return dp[n];
    }
};
}

int main(int argc, char **argv) {
    int n = 10;
    std::cout << leetcode_cpp::Solution2().nthUglyNumber(n) << std::endl;
    return 0;
}