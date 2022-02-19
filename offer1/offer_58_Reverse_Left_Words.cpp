#include <vector>
#include <string>
#include <iostream>
#include <deque>

/*
@
LeetCode 剑指offer
time: 2022-01-30 20:21:14
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    std::string reverseLeftWords(std::string s, int n) {
        int sLen = s.length();
        reverseSubstr(s, 0, n - 1);
        reverseSubstr(s, n, sLen - 1);
        reverseSubstr(s, 0, sLen - 1);
        return s;
    }

private:
    void reverseSubstr(std::string &s, int lo, int hi) {
        int mid = lo + ((hi - lo) >> 1);
        while (lo < hi) {
            std::swap(s[lo], s[hi]);
            ++lo;
            --hi;
        }
    }
};
}

int main(int argc, char **argv) {
    std::string s{"lrloseumgh"};
    int k = 6;
    std::cout << leetcode_cpp::Solution().reverseLeftWords(s, k) << std::endl;
    return 0;
}