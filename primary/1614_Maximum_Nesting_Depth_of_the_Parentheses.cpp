#include <vector>
#include <string>
#include <iostream>
/*
@
project: Leetcode
time: 2022-01-07 20:13:34
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int maxDepth(std::string s) {
        int ans = 0, size = 0;
        for (const auto &ch : s) {
            if (ch == '(') {
                ++size;
                ans = std::max(ans, size);
            } else if (ch == ')') {
                --size;
            }
        }
        return ans;
    }
};
}

int main(int argc, char **argv) {
    std::string s {"1"};
    std::cout << leetcode_cpp::Solution().maxDepth(s) << std::endl;
    return 0;
}