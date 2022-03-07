#include <vector>
#include <string>
#include "limits.h"
#include <iostream>
/*
@
LeetCode 剑指offerII
time: 2022-03-04 20:57:04
author: edinw
@
*/

/*
**  Given a string s, return true if the s can be palindrome after deleting at most one character from it.
*/


namespace leetcode_cpp {
class Solution {
public:
    bool validPalindrome(std::string &s) {
        int sLen = s.length();

        auto checkPalindrome = [&](int left, int right) -> bool {
            while (left <= right && s[left] == s[right]) {
                ++left;
                --right;
            }


            return left > right;
        };

        int lo = 0, hi = sLen - 1;
        
        while (lo < hi) {
            char c1 = s[lo], c2 = s[hi];
            if (c1 == c2) {
                ++lo;
                --hi;
            } else {
                return checkPalindrome(lo + 1, hi) ||checkPalindrome(lo, hi - 1);
            }
        }

        return true;
    }
};
}

int main(int argc, char **argv) {
    std::string s {"abca"};

    std::cout << std::boolalpha << leetcode_cpp::Solution().validatePalindrome(s) << std::endl;

    return 0;
}
