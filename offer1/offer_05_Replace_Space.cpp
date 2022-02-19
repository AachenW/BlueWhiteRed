#include <vector>
#include <string>
#include <iostream>
#include <deque>

/*
@
LeetCode 剑指offer
time: 2022-01-30 20:11:25
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    std::string replaceSpace(std::string s) {
        std::vector<std::string> strs;
        std::string temp;
        for (const auto &ch: s) {
            if (' ' == ch) {
                strs.emplace_back(temp);
                temp.clear();
            } else {
                temp.push_back(ch);
            }
        }

        if (!temp.empty()) {
            strs.emplace_back(temp);
        }
        int endSpace = s.back() == ' ';
        std::string replaceStr = "%20";
        std::string ans;
        for (const auto &str: strs) {
            ans.append(str + replaceStr);
        }
        if (!endSpace) {
            ans = ans.substr(0, ans.length() - 3);
        }
        return ans;
    }
};
}

int main(int argc, char **argv) {
    std::string s{"We are happy. "};
    std::cout << leetcode_cpp::Solution().replaceSpace(s) << std::endl;
    return 0;
}