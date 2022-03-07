#include <vector>
#include <string>
#include "limits.h"
#include <iostream>
/*
@
LeetCode 剑指offer
time: 2022-02-25 20:21:07
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    std::string convert(std::string s, int numRows) {
        std::vector<std::string> res(numRows);
        int flag = -1, i = 0;

        for (const char c: s) {
            res[i] += c;
            if (0 == i || i == numRows - 1) {
                flag = -flag;
            }
            i += flag;
        }
        
        std::string ans;
        for (const auto &str: res) {
            ans += str;
        }

        return ans;
    }
};
}

int main(int argc, char **argv) {
    std::string s{"AB"};
    int numRows = 1;
    std::cout << leetcode_cpp::Solution().convert(s, numRows) << std::endl;
    return 0;
}