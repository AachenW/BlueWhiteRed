#include <vector>
#include <functional>
#include <iostream>
/*
@
LeetCode 主站
time: 2022-01-29 22:33:41
author: edinw
@
*/

/*
**  Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation 
**      of i.
*/

namespace leetcode_cpp {
class Solution {
public:
    std::vector<int> countBits(int n) {
        std::function<int(int)> countBit = [] (int num) -> int {
            int cnt = 0;
            while (num > 0) {
                num &= (num - 1);
                ++cnt;
            }
            return cnt;
        };

        std::vector<int> ans;
        for (int i = 0; i <= n; ++i) {
            ans.emplace_back(countBit((i)));
        }

        return ans;
    }
};

class Solution2 {
public:
    std::vector<int> countBits(int n) {
        std::vector<int> ans(n + 1);
        int highBit = 0;
        for (int i = 1; i < n + 1; ++i) {
            if ((i & (i - 1)) == 0) {
                highBit = i;
            }
            ans[i] = ans[i - highBit] + 1;
        }

        return ans;
    }
};
}

int main(int argc, char **argv) {
    int n = 5;
    auto ans = leetcode_cpp::Solution().countBits(n);
    for (const int &num: ans) {
        std::cout << num << ", ";
    }
    std::cout << std::endl;
    return 0;
}