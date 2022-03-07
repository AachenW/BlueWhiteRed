#include <vector>
#include <string>
#include "limits.h"
#include <iostream>
/*
@
LeetCode 剑指offerII
time: 2022-03-04 20:48:29
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    bool isPalindrome(std::string &s) {
        int sLen = s.length();
        int lo = 0, hi = sLen - 1;

        while (lo < hi) {
            while (lo < hi && !isalpha(s[lo])) {
                ++lo;
            }

            while (lo < hi && !isalpha(s[hi])) {
                --hi;
            }

            if (lo < hi) {
                if (tolower(s[lo]) != tolower(s[hi])) {
                    return false;
                } else {
                    ++lo;
                    --hi;
                }
            }
        }

        return true;
    }
};
}

int main(int argc, char **argv) {
    std::string s1{"A man, a plan, a canal: Panama"};

    std::cout << std::boolalpha << leetcode_cpp::Solution().isPalindrome(s1) << std::endl;

    return 0;
}
