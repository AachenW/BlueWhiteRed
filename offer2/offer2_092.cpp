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
class Solution {
public:
    //dp[i][0]表示前i个元素，最后一个元素为0的最小翻转次数；
    //dp[i][1]表示前i个元素，最后一个元素为1的最小翻转次数
    int minFlipsMonoIncr(std::string s) {
        auto sLength = s.size();
        std::vector<std::vector<int>> dp(sLength, std::vector<int>(2, 0));
        
        // initialization
        dp[0][0] = s[0] == '0' ? 0 : 1;
        dp[0][1] = s[0] == '1' ? 0 : 1;
        
        // states transfer
        for (decltype(sLength) i = 1; i < sLength; ++i) {
            // 若当前字符i下标的字符是‘0’:
            if (s.at(i) == '0') {
                // zero[i]不需要转换，zero[i] = zero[i-1].
                dp[i][0] = dp[i - 1][0];                               
                // one[i]需要将‘0’转换为‘1’,有两种情况：1.若前一位是‘0’转换的‘1’,则one[i] = one[i-1] + 1;2.若前一位本身就是'1',则one[i] = zero[i-1] + 1;
                dp[i][1] = std::min(dp[i - 1][1], dp[i - 1][0]) + 1;   
            } 
            // 若当前下标i的字符为‘1’:
            else if (s.at(i) == '1') {
                // zero[i]需要把'1'转换成'0',当前位的最小转换次数应该比前一位转换次数多一次
                dp[i][0] = dp[i - 1][0] + 1;   
                // one[i]不需要转换,但也有两种情况：1.若前一位是‘0’，则one[i] = zero[i-1];2.若前一位是‘1’，则one[i] = one[i-1];
                dp[i][1] = std::min(dp[i - 1][0], dp[i - 1][1]);
            }
        }
        return std::min(dp[sLength - 1][0], dp[sLength - 1][1]);
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
        int cntZero = s.at(0) == '0' ? 0 : 1;
        int cntOne = s.at(0) == '1' ? 0 : 1;
        int tempZero = 0, tempOne = 0;
        
        // states transfer
        for (decltype(sLength) i = 1; i < sLength; ++i) {
            if (s.at(i) == '0') {           // 若当前字符i下标的字符是‘0’:
                // zero[i]不需要转换，zero[i] = zero[i-1].
                tempZero = cntZero;                     
                // one[i]需要将‘0’转换为‘1’,有两种情况：1.若前一位是‘0’转换的‘1’,则one[i] = one[i-1] + 1;2.若前一位本身就是'1',则one[i] = zero[i-1] + 1;
                tempOne = std::min(cntOne, cntZero) + 1;    
            } else if (s.at(i) == '1') {    // 若当前下标i的字符为‘1’:
                // zero[i]需要把'1'转换成'0',当前位的最小转换次数应该比前一位转换次数多一次
                tempZero = cntZero + 1;
                // one[i]不需要转换,但也有两种情况：1.若前一位是‘0’，则one[i] = zero[i-1];2.若前一位是‘1’，则one[i] = one[i-1];
                tempOne = std::min(cntOne, cntZero);
            }
            cntZero = tempZero;
            cntOne = tempOne;
        }
        return std::min(cntOne, cntZero);
    }
};
}

int main(int argc, char **argv) {
    std::string s{"100000001010000"};
    std::cout << leetcode_cpp::Solution2().minFlipsMonoIncr(s) << std::endl;
    return 0;
}