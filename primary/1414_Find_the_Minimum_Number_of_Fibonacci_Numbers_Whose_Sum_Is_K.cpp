#include <vector>
#include <iostream>
#include <map>
/*
@
project: Leetcode
time: 2022-02-03 19:00:53
author: edinw
@
*/

/*
**  Given an integer k, return the minimum number of Fibonacci numbers whose sum is equal to k. The same Fibonacci number can be used multiple times.
**  The Fibonacci numbers are defined as:
**      F1 = 1
**      F2 = 1
**      Fn = Fn-1 + Fn-2 for n > 2.
**  It is guaranteed that for the given constraints we can always find such Fibonacci numbers that sum up to k.
*/

namespace leetcode_cpp {
class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        std::vector<int> fibonacci;
        fibonacci.emplace_back(1);
        fibonacci.emplace_back(1);
        int cur = 1, prev = 1;
        while (fibonacci.back() <= k) {
            fibonacci.emplace_back(cur + prev);
            prev = cur;
            cur = fibonacci.back();
        }
        fibonacci.pop_back();

        int count = 0;
        while (!fibonacci.empty()) {
            if (fibonacci.back() == k) {
                return count + 1;
            } else if (fibonacci.back() < k){
                k -= fibonacci.back();
                ++count;
                std::cout << fibonacci.back() << " ";
                fibonacci.pop_back();
            } else {
                fibonacci.pop_back();
            }
        }
        return -1;
    }
}; 
}

int main(int argc, char **argv) {
    int k = 19;
    std::cout << leetcode_cpp::Solution().findMinFibonacciNumbers(k) << std::endl;
    return 0;
}