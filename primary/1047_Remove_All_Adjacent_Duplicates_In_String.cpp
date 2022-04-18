#include <bits/stdc++.h>

/*
@
project: Leetcode
time: 2022-03-23 22:09:03
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public: 
    std::string removeDuplicates(std::string s) {
        std::string stk;
        for (char ch: s) {
            if (!stk.empty() && stk.back() == ch) {
                stk.pop_back();
            } else {
                stk.push_back(ch);
            }
        }

        return stk;
    }
};
}

int main(int argc, char **argv) {
    std::string s{"abbaca"};
    std::cout << leetcode_cpp::Solution().removeDuplicates(s) << std::endl;

    return 0;
}