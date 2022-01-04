#include <vector>
#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <numeric>
#include <string>
#include <limits.h>

/*
@
LeetCode 剑指offerⅡ
time: 2022-01-01 19:49:05
author: edinw
@
*/

/*
本题与主站 76 题相似（本题答案不唯一）：https://leetcode-cn.com/problems/minimum-window-substring/
给定两个字符串 s 和 t 。返回 s 中包含 t 的所有字符的最短子字符串。如果 s 中不存在符合条件的子字符串，则返回空字符串 "" 。
如果 s 中存在多个符合条件的子字符串，返回任意一个。

注意： 对于 t 中重复字符，我们寻找的子字符串中该字符数量必须不少于 t 中该字符数量。

*/


namespace leetcode_cpp {
class Solution {
public:
    std::string minWindow(std::string s, std::string t) {
        // 统计t中所有的字符以及它们的个数
        for (const auto &c : t) {
           ++ori[c];
        } 
        int l = 0, r = -1;    // 右窗口为-1,意味着窗口的起始位置在s[0]的左侧
        int len = INT_MAX, ansL = -1;
    
        while (r < int(s.size())) {
            // 移动右窗口
            if (ori.find(s[++r]) != ori.end()) {
                // 如果字符串s中，当前字符在字符串t中出现过，则更新cnt哈希表
                ++cnt[s[r]];
            }
            while (check() && l <= r) {
                // 如果满足最小覆盖子串条件，则更新len和ansL;
                if (r - l + 1 < len) {
                    len = r - l + 1;
                    ansL = l;
                }
                if (ori.find(s[l]) != ori.end()) {
                    // 如果字符串t中对应s[l]的字符还存在，则减少cnt哈希表中对应字符的个数
                    --cnt[s[l]];    
                }
                ++l;    // 移动左窗口
            }
        }
        return ansL == -1 ? std::string() : s.substr(ansL, len);
    }
private:
    // 辅助函数，检查当前窗口内字符串包含t中的所有字符，并且对应的个数都不小于t中各字符的个数
    bool check() {
        for (const auto &p : ori) {
            if (cnt[p.first] < p.second) {
                return false;
            }
        }
        return true;
    }

    std::unordered_map<char, int> ori;          // t中所有字符以及它们的个数
    std::unordered_map<char, int> cnt;          // 窗口中所有的字符以及它们的个数
};
}

int main(int argc, char **argv) {
    std::string s{"ADOBECODEBANC"}, t{"ABC"};
    std::cout << leetcode_cpp::Solution().minWindow(s, t) << std::endl;
    return 0;
}