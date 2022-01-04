#include <vector>
#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <string>

/*
@
LeetCode 剑指offerⅡ
time: 2022-01-01 19:49:05
author: edinw
@
*/

/*
本题与主站 3 题相同： https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
给定一个字符串 s ，请你找出其中不含有重复字符的最长连续子字符串的长度。
*/

namespace leetcode_cpp {
class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        // 哈希集合，记录每个字符是否出现过
        std::unordered_set<char> occ;
        using sz = decltype(s.size());
        sz sLength = s.size();
        // 右指针，初始值为 -1，相当于我们在字符串的左边界的左侧，还没有开始移动
        sz rk = -1, ans = 0;
        // 枚举左指针的位置，初始值隐性地表示为 -1
        for (sz i = 0; i < sLength; ++i) {
            if (i != 0) {
                // 左指针向右移动一格，移除一个字符
                occ.erase(s[i - 1]);
            }
            while (rk + 1 < sLength && !occ.count(s[rk + 1])) {
                // 不断地移动右指针
                occ.insert(s[rk + 1]);
                ++rk;
            }
            // 第 i 到 rk 个字符是一个极长的无重复字符子串
            ans = std::max(ans, rk + 1 - i);
        }
        return ans;
    }
};
}

int main (int argc, char **argv) {
    std::string str {"abcabcbb"};
    std::cout << leetcode_cpp::Solution().lengthOfLongestSubstring(str) << std::endl;
    return 0;
}