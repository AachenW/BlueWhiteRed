#include <iostream>
#include <vector>
#include <functional>
#include <queue>
/*
@
LeetCode 剑指offer
time: 2022-02-20 22:15:33
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    std::vector<int> printNumbers(int n) {
        std::string s;
        s.resize(n, '0');
        std::vector<int> ans;
        
        auto save = [&]() {
            int idx = 0;
            while (idx < n && s[idx] == '0') {
                ++idx;
            }

            if (idx != n) {
                ans.emplace_back(std::stoi(s.substr(idx)));
            }
        };

        std::function<void(int)> backtrack = [&] (int idx) {
            if (idx == n) {
                save();
                return;
            }

            for (int i = 0; i <= 9; ++i) {
                s[idx] = i + 48;
                backtrack(idx + 1);
            }
        };

        backtrack(0);
        return ans;

    }
};
}

int main(int argc, char **argv) {
    int n = 1;
    auto ans = leetcode_cpp::Solution().printNumbers(n);
    for (const int num: ans) {
        std::cout << num << ", ";
    }
    std::cout << std::endl;

    return 0;
}