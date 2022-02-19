#include <iostream>
#include <string>

/*
@
LeetCode 剑指offer
time: 2022-02-09 21:00:33
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    std::string reverseWords(std::string s) {
        int sLen = s.length();
        std::string ans;
        if (0 == sLen) {
            return ans;
        }

        int hi = sLen - 1;
        while (hi >= 0) {
            while (hi >= 0 && s[hi] == ' ') {
                --hi;                               // 从后往前寻找第一个字符
            }
            if (hi < 0) {
                break;
            }
            int lo = hi;
            while (lo >= 0 && s[lo] != ' ') {
                --lo;                               // 从后往前寻找第一个空格
            }
            // 添加单词到结果中 (如果单词前面有连续的空格存在，则一并添加到res中，到最后返回时再处理)
            ans += s.substr(lo + 1, hi - lo);
            ans += " ";
            hi = lo;
        }

        if (!ans.empty()) {
            ans.pop_back();                         // 去除最后一个字符空格
        }
        return ans;
    }
};
}

int main(int argc, char **argv) {
    std::string s {"  hello world!  "};
    std::cout << leetcode_cpp::Solution().reverseWords(s) << std::endl;
    return 0;
}