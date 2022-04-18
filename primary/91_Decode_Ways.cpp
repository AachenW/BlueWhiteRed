#include <bits/stdc++.h>

/*
@
projetc: leetcode
time: 2022-03-20 19:31:39
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int numDecodings(std::string s) {
        int sLen = s.length();
        std::vector<int> dp(sLen + 1);
        dp[0] = 1;  // 即空字符串可以有 11 种解码方法，解码出一个空字符串。

        for (int i = 1; i <= sLen; ++i) {
            if ('0' != s[i - 1]) {
                dp[i] += dp[i - 1];
            }
            if (i > 1 && '0' != s[i - 2] && ((s[i - 2] - '0') * 10 + (s[i - 1] - '0') <= 26)) {
                dp[i] += dp[i - 2];
            }
        }

        return dp[sLen];
    }
};
}

int main(int argc, char **argv) {
    std::string s("11106");

    std::cout << leetcode_cpp::Solution().numDecodings(s) << std::endl;

    return 0;
}