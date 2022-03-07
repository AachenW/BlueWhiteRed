#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
/*
@
projetc: leetcode
time: 2022-03-02 21:26:20
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int longestPalindrome(std::string s) {
        std::unordered_map<char, int> count;
        int ans = 0;
        for (char c : s)
            ++count[c];
        for (auto p : count) {
            int v = p.second;
            ans += v / 2 * 2;
            if (v % 2 == 1 and ans % 2 == 0)
                ++ans;
        }
        return ans;
    }
};
}

int main(int argc, char **argv) {
    std::string s{"abccccdd"};

    std::cout << leetcode_cpp::Solution().longestPalindrome(s) << std::endl;

    return 0;
}