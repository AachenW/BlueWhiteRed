#include <string>
#include <iostream>
/*
@
LeetCode 剑指offerⅡ
time: 2022-01-01 21:17:53
author: edinw
@
*/


namespace leetcode_cpp {
class Solution {
public:
    bool isPalindrome(std::string s) {
        typedef decltype(s.size()) sz;
        sz l = 0, r = s.size() - 1;
        while (l < r) {
            while (l < r && !isalnum(s[l])) {
                ++l;
            }
            while (l < r && !isalnum(s[r])) {
                --r;
            }
            if (l < r) {
                if (tolower(s[l]) != tolower(s[r])) {
                    return false;
                }
                ++l;
                --r;
            }
        }
        return true;
    }
};
}

int main(int argc, char **agrv) {
    std::string s{"race a car"};
    std::cout << leetcode_cpp::Solution().isPalindrome(s) << std::endl;
    return 0;
}