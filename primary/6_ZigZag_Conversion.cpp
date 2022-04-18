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

class Solution2 {
public:
    std::string convert(std::string s, int numRows) {
        int sLen = s.length();
        std::vector<std::string> vs(numRows, "");
        int idx = 0;
        while (idx < sLen) {
            for (int j = 0; j < numRows && idx < sLen; ++j) {
                vs[j].push_back(s[idx++]);
            }

            for (int j = numRows - 2; j >= 1 && idx < sLen; --j) {
                vs[j].push_back(s[idx++]);
            }
        }

        std::string ans;
        for (const auto &v: vs) {
            ans += v;
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