#include <bits/stdc++.h>

/*
@
projetc: leetcode
time: 2022-05-02 10:39:00 
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int characterReplacement(std::string &s, int k) {
        int sLen = s.length();
        std::vector<int> chars(26);
        int left = 0, right = 0;
        int maxn = INT_MIN;

        while (right < sLen) {
            ++chars[s[right] - 'a'];
            maxn = std::max(maxn, chars[s[right] - 'a']);
            while (right - left + 1 - maxn > k) {
                --chars[s[left] - 'a'];
                ++left;
            }
            ++right;
        }

        return right - left;
    }
};
}

int main(int argc, char **argv) {
    std::string s{"AABABBA"};
    int k = 1;
    std::cout << leetcode_cpp::Solution().characterReplacement(s, k) << std::endl;

    return 0;
}

