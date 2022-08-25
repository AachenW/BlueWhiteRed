#include <bits/stdc++.h>

/*
@
projetc: leetcode
time: 2022-05-04 12:50:38 
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    std::string licenseKeyFormatting(std::string s, int k) {
        std::string ans;
        int cnt = 0;
        int sLen = s.length();

        for (int i = sLen - 1; i >= 0; --i) {
            if (s[i] != '-') {
                ans.push_back(std::toupper(s[i]));
                ++cnt;
                if (0 == cnt % k) ans.push_back('-');
            }
        }
        if (ans.size() > 0 && '-' == ans.back()) ans.pop_back();

        std::reverse(ans.begin(), ans.end());
        
        return ans;
    }
};
}

int main(int argc, char **argv) {
    std::string s{"5F3Z-2e-9-w"};
    int k = 4;
    std::cout << leetcode_cpp::Solution().licenseKeyFormatting(s, k) << '\n';
    return 0;
}
