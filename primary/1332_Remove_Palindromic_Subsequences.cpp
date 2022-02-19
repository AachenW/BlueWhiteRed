#include <vector>
#include <iostream>
#include <map>
/*
@
project: Leetcode
time: 2022-01-22 19:35:00
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int removePalindromeSub(std::string s) {
        int sLength = s.length();
        for (int i = 0; i < sLength >> 1; ++i) {
            if (s[i] != s[sLength - i - 1]) {
                return 2;
            }
        }
        return 1;
    }
};
}

int main(int argc, char **argv) {
    std::string s{"abb"};
    std::cout << leetcode_cpp::Solution().removePalindromeSub(s) << std::endl;
    return 0;
}