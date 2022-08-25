#include <bits/stdc++.h>

/*
@
LeetCode 
time: 2022-04-24 18:23:53
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    void reverseString(std::vector<char> &s) {
        int sLen = s.size();

        int mid = sLen >> 1;
        for (int i = 0; i < mid; ++i) {
            std::swap(s[i], s[sLen - i - 1]);
        }

        return;
    }
};
}

int main(int argc, char **argv) {
    std::vector<char> s{'h', 'e', 'l', 'l', 'o'};
    
    leetcode_cpp::Solution().reverseString(s);
    for (char c: s) {
        std::cout << c << ",";
    }
    std::cout << '\n';

    return 0;
}