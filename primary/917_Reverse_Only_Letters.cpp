#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
/*
@
LeetCode
time: 2022-02-23 19:40:00
author: edinw
@
*/

/*
**  Given a string s, reverse the string according to the following rules:
**      All the characters that are not English letters remain in the same position.
**      All the English letters (lowercase or uppercase) should be reversed.
**
**  Return s after reversing it.
*/

namespace leetdcode_cpp {
class Solution {
public:
    std::string reverseOnlyLetters (std::string s) {
        int sLen = s.length();
        int lo = 0, hi = sLen - 1;

        while (lo < hi) {
            while (lo <= hi && !isalpha(s[lo])) {
                ++lo;
            }
            while (lo <= hi && !isalpha(s[hi])) {
                --hi;
            }
            if (lo < hi) {
                std::swap(s[lo++], s[hi--]);
            }
        }

        return s;
    }
};
}

int main(int argc, char **argv) {
    std::string s {"ab-cd"};
    std::cout << leetdcode_cpp::Solution().reverseOnlyLetters(s) << std::endl;
    
    return 0;
}