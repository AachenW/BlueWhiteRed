#include <bits/stdc++.h>

/*
@
projetc: leetcode
time: 2022-05-09 09:30:23
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    std::vector<int> diStringMatch(std::string s) {
        std::vector<int> ans;
        int sLen = s.length();
        int left = 0, right = sLen;
        for (int i = 0; i <= sLen; ++i) {
            if (0 == i) {
                int n = 'I' == s[i] ? left++ : right--;
                ans.emplace_back(n);
            } else {
                if ('I' == s[i]) ans.emplace_back(left++);
                else ans.emplace_back(right--);
            }
        }

        return ans;
    }
};
}

int main(int argc, char **argv) {
    std::string s{"DDI"};
    auto ans = leetcode_cpp::Solution().diStringMatch(s);
    for (int output: ans) std::cout << output << ',';
    std::cout << std::endl;
    return 0;
}