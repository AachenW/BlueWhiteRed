#include <deque>
#include <string>
#include <iostream>
/*
@
LeetCode HOT 100
time: 2022-02-03 23:42:12
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    bool isValid(std::string s) {
        std::deque<char> stack;
        for (const auto &ch: s) {
            if (!stack.empty()) {
                if (')' == ch && '(' == stack.back()) {
                    stack.pop_back();
                } else if (']' == ch && '[' == stack.back()) {
                    stack.pop_back();
                } else if ('}' == ch && '{' == stack.back()) {
                    stack.pop_back();
                } else {
                    stack.emplace_back(ch);
                }
            } else {
                stack.emplace_back(ch);
            }        
        }
        return stack.empty();
    }
};
}

int main(int argc, char **argv) {
    std::string s{"}"};
    std::cout << std::boolalpha << leetcode_cpp::Solution().isValid(s) << std::endl;
    return 0;
}