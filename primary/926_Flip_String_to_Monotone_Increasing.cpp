#include <string>
#include <vector>
#include <iostream>
/*
@
LeetCode 剑指offerⅡ
time: 2022-01-05 22:00:48
author: edinw
@
*/

/*
注意：本题与主站 926 题相同： https://leetcode-cn.com/problems/flip-string-to-monotone-increasing/

如果一个由 '0' 和 '1' 组成的字符串，是以一些 '0'（可能没有 '0'）后面跟着一些 '1'（也可能没有 '1'）的形式组成的，那么该字符串是 单调递增 的。

我们给出一个由字符 '0' 和 '1' 组成的字符串 s，我们可以将任何 '0' 翻转为 '1' 或者将 '1' 翻转为 '0'。

返回使 s 单调递增 的最小翻转次数。

*/

namespace leetcode_cpp {
class Solution1_0 {
public:
    //dp[i][0]表示前i个元素，最后一个元素为0的最小翻转次数；
    //dp[i][1]表示前i个元素，最后一个元素为1的最小翻转次数
    int minFlipsMonoIncr(std::string s) {
        auto sLength = s.size();
        std::vector<std::vector<int>> dp(2, std::vector<int>(2, 0));
        
        // initialization
        s[0] == '0' ? dp[0][1] = 1 : dp[0][0] = 1;

        // states transfer function
        for (int i = 1; i < sLength; ++i) {
            int prev0 = dp[(i - 1) % 2][0];
            int prev1 = dp[(i - 1) % 2][1];
            dp[i % 2][0] = prev0 + (s[i] != '0');
            dp[i % 2][1] = std::min(prev0, prev1) + (s[i] != '1');
        }

        int last = (sLength - 1) % 2;

        return std::min(dp[last][0], dp[last][1]);
    }
};

class Solution1_1 {
public:
    int minFlipsMonoIncr(std::string s) {
        int dp0 = 0, dp1 = 0;
        for (char c: s) {
            int dp0New = dp0, dp1New = std::min(dp0, dp1);
            if ('1' == c) 
                ++dp0New;
            else 
                ++dp1New;
            dp0 = dp0New;
            dp1 = dp1New;
        }
        return std::min(dp0, dp1);
    }
};

class Solution2{
public:
    int minFlipsMonoIncr(std::string s) {
        auto sLength = s.size();
        if (0 == sLength) {
            return 0;
        }
        
        // initialization
        int dp = 0, cnt = 0;
        
        // states transfer
        for (decltype(sLength) i = 1; i < sLength; ++i) {
            if ('1' == s[i]) {
                ++cnt;  // 如果s[i] == '1'，那么这个字符不影响翻转次数
            } else {
                // 若s[i] == '0'，那我们有两种情况：
                //  1. 将s[i]由0翻转到1。
                //  2. 将前面的字符串s[0:i-1]中所有1翻转到0，两种情况取最小值，有dp[i] = min{dp[i - 1] + 1, cnt}
                dp = std::min(dp + 1, cnt);
            }
        }

        return dp;
    }
};
}

int main(int argc, char **argv) {
    std::string s{"100000001010000"};
    std::cout << leetcode_cpp::Solution2().minFlipsMonoIncr(s) << std::endl;
    return 0;
}
