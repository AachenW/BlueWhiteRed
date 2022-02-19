#include <vector>
#include <iostream>
/*
@
LeetCode 剑指offer
time: 2022-02-06 19:15:55
author: edinw
@
*/

/*
**  给定一个数字，我们按照如下规则把它翻译为字符串：0 翻译成 “a” ，1 翻译成 “b”，……，11 翻译成 “l”，……，25 翻译成 “z”。一个数字可能有多个翻译。请编程实现一个函数，用来计算一个
**      数字有多少种不同的翻译方法。
*/

namespace leetcode_cpp {
class Solution {
public:
    int translateNum(int num) {
        std::string src = std::to_string(num);
        int sLen = src.length();

        // dp[i] 表示以第 i 位结尾的前缀串翻译的方案数
        std::vector<int> dp(sLen + 1);
        // initialization
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= sLen; ++i) {
            std::string temp = src.substr(i - 2, 2);
            // 
            if (temp <= "25" && temp >= "10") {
                dp[i] = dp[i - 1] + dp[i - 2];  // 单独翻译对 dp[i] 的贡献为dp[i - 1];第i−1位和第i位连起来一起翻译，对dp[i]的贡献为dp[i − 2]

            } else {
                dp[i] = dp[i - 1];  // 单独翻译对 dp[i] 的贡献为dp[i - 1];
            }
        }
        return dp[sLen];
    }
};
}

int main(int argc, char **argv) {
    int num = 12258;
    std::cout << leetcode_cpp::Solution().translateNum(num) << std::endl;
    return 0;
}