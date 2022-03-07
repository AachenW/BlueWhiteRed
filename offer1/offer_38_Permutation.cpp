#include <vector>
#include <iostream>
#include <functional>
#include <set>
/*
@
LeetCode 剑指offer
time: 2022-02-19 23:01:46
author: edinw
@
*/

/*
**  输入一个字符串，打印出该字符串中字符的所有排列。
**  
**  你可以以任意顺序返回这个字符串数组，但里面不能有重复元素。
*/

namespace leetcode_cpp {
class Solution{
public:
    std::vector<std::string> permutation(std::string s) {
        std::vector<std::string> ans;
        std::set<std::string> filter;
        int sLen = s.length();
        std::vector<int> visited(sLen);
        std::function<void(std::string)> bactrack = [&](std::string candidate) {
            if (candidate.size() == sLen) {
                if (filter.find(candidate) == filter.end()) {
                    filter.insert(candidate);
                }
                return;
            }
            for (int i = 0; i < sLen; ++i) {
                if (!visited[i]) {
                    visited[i] = 1;
                    bactrack(candidate + s[i]);
                    visited[i] = 0;
                }
            }
        };

        std::string candidate = "";
        bactrack(candidate);
        ans.assign(filter.begin(), filter.end());
        return ans;
    }
};
}

int main(int argc, char **argv) {
    std::string s{"abc"};
    auto ans = leetcode_cpp::Solution().permutation(s);
    for (const auto &str: ans) {
        std::cout << str << std::endl;
    }

    return 0;
}