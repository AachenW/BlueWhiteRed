#include <string>
#include <unordered_map>
#include <limits.h>
#include <iostream>
/*
@
projetc: leetcode
time: 2022-01-01 20:14:00
author: edinw
@
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