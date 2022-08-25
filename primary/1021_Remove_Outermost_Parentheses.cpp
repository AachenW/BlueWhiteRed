#include <bits/stdc++.h>

/*
@
project: Leetcode
time: 2022-05-28 10:34:16
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    std::string removeOuterParentheses(std::string s) {
        std::deque<char> sk;
        int sLen = s.length();
        std::string ans;

        for (int i = 0; i < sLen; ++i) {
            if (sk.empty()) sk.emplace_back(s[i]);
            else if (1 == sk.size() && ')' == s[i] && '(' == sk.back()) {
                sk.pop_back();
            } else {
                if ('(' == s[i]) {
                    sk.emplace_back(s[i]);
                } else {
                    sk.pop_back();
                }
                ans.push_back(s[i]);
            }    
        }

        return ans;
    }
};
}

int main(int argc, char **argv) {
    std::string s{"(()())(())"};
    std::cout << leetcode_cpp::Solution().removeOuterParentheses(s) << std::endl;
    return 0;
}