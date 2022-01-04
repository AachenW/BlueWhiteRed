#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <numeric>
/*
@
LeetCode 剑指offerⅡ
time: 2021-12-26 19:14:29
author: edinw
@
*/

/*
本题与主站 567 题相同： https://leetcode-cn.com/problems/permutation-in-string/
给定两个字符串 s1 和 s2，写一个函数来判断 s2 是否包含 s1 的某个变位词。
换句话说，第一个字符串的排列之一是第二个字符串的子串。
*/

namespace leetcode_cpp {
class Solution{
public:
    bool checkInclusion(std::string s1, std::string s2) {
        typedef decltype(s1.size()) sz;
        sz s1Length = s1.size(), s2Length = s2.size();
        if (s1Length > s2Length) {
            return false;
        }
        std::vector<int> cnt(26);
        // 统计s1中所有字符出现的次数, 且将所有出现的字符在cnt中对应的值-1
        for (sz i = 0; i < s1Length; ++i) {
            --cnt[s1[i] - 'a'];
        }
        int left = 0;
        for (sz right = 0; right < s2Length; ++right) {
            int x = s2[right] - 'a';
            ++cnt[x];
            // 当前搜索的字符在s1中没出现过
            while (cnt[x] > 0) {
                --cnt[s2[left] - 'a'];  // left和right指向同一个位置
                ++left;                 // 滑动左窗口
            }
            // 当前搜索的字符在s1中没出现过，且窗口大小==s1的长度，返回true
            if (right - left + 1 == s1Length) {
                return true;
            }
        }
        return false;
    }
};
}

int main(int argc, char **argv) {
    std::string s1("ab"), s2("eidboaoo");
    std::cout << leetcode_cpp::Solution().checkInclusion(s1, s2) << std::endl;
    return 0;
}