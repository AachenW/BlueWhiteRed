#include <bits/stdc++.h>

/*
@
project: Leetcode
time: 2022-04-19 09:05:05
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    std::vector<int> shortestToChar(std::string &s, char c) {
        int sLen = s.length();
        std::vector<int> ans(sLen, 0);
        std::vector<int> mono_stack(sLen);

        for (int i=0; i<sLen; ++i) {
            if (s[i] == c) {
                while (!mono_stack.empty() && s[mono_stack.back()]!=c){
                    int idx = mono_stack.back(); mono_stack.pop_back();
                    ans[idx] = i - idx;
                }
            }
            mono_stack.emplace_back(i);
        }
        
        mono_stack.clear();
        for (int i=sLen-1; i>=0; --i) {
            if (s[i] == c) {
                while (!mono_stack.empty() && s[mono_stack.back()]!=c) {
                    int idx = mono_stack.back(); mono_stack.pop_back();
                    if (ans[idx]) ans[idx] = std::min(ans[idx], idx - i); 
                    else ans[idx] = idx - i;
                }
            }
            mono_stack.emplace_back(i);
        }

        return ans;
    }
};
}

int main(int argc, char **argv) {
    std::string s{"aaba"};
    char c = 'b';

    auto ans = leetcode_cpp::Solution().shortestToChar(s, c);

    for (int output: ans) {
        std::cout << output << " ";
    }
    std::cout << '\n';

    return 0;
}
