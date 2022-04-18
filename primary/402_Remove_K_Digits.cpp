#include <bits/stdc++.h>

/*
@
projetc: leetcode
time: 2022-03-23 10:33:50
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    std::string removeKdigits(std::string num, int k) {
        std::vector<int> mono_stk;
        for (auto &&digit: num) {
            while (!mono_stk.empty() && mono_stk.back() > digit && k > 0) {
                mono_stk.pop_back();
                --k;
            }
            mono_stk.emplace_back(digit);
        }

        for (; k > 0; --k) {
            mono_stk.pop_back();
        }

        std::string ans = "";
        bool isLeadingZero = true;
        for (auto &&digit: mono_stk) {
            if (isLeadingZero && '0' == digit) {
                continue;
            }
            isLeadingZero = false;
            ans += digit;
        }

        return "" == ans ? "0" : ans;
    }
};
}

int main(int argc, char **argv) {
    std::string num{"1432219"};
    int k = 3;

    std::cout << leetcode_cpp::Solution().removeKdigits(num, k) << std::endl;

    return 0;
}