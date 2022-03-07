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
}

int main(int argc, char **argv) {
    int n = 4;
    std::cout << leetcode_cpp::Solution().nthUglyNumber(n) << std::endl;
    return 0;
}