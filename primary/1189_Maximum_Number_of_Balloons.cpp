#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
/*
@
project: leetcode
time: 2022-02-13 21:16:38
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int maxNumberOfBalloons(std::string text) {
        std::vector<int> cnt(5);
        for (const auto &ch: text) {
            if ('b' == ch) {
                ++cnt[0];
            } else if ('a' == ch) {
                ++cnt[1];
            } else if ('l' == ch) {
                ++cnt[2];
            } else if ('o' == ch) {
                ++cnt[3];
            } else if ('n' == ch) {
                ++cnt[4];
            }
        }

        cnt[2] >>= 1;
        cnt[3] >>= 1;

        return *std::min_element(cnt.begin(), cnt.end());
    }
};
}

int main(int argc, char **argv) {
    std::string text {"balon"};
    std::cout << leetcode_cpp::Solution().maxNumberOfBalloons(text) << std::endl;
    return 0;
}