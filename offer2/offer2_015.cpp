#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <numeric>
/*
@
LeetCode 剑指offerⅡ
time: 2021-12-26 23:02:57
author: edinw
@
*/

/*
本题与主站 438 题相同： https://leetcode-cn.com/problems/find-all-anagrams-in-a-string/
给定两个字符串 s 和 p，找到 s 中所有 p 的 变位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。
变位词 指字母相同，但排列不同的字符串。
*/

namespace leetcode_cpp {
class Solution{
public:
    std::vector<int> findAnagrams(std::string s, std::string p) {
        typedef decltype(s.size()) sz;
        sz sLen = s.size(), pLen = p.size();
        if (sLen < pLen) {
            return std::vector<int>();
        }
        std::vector<int> ans;
        std::vector<int> sCount(26);
        std::vector<int> pCount(26);
        for (sz i = 0; i < pLen; ++i) {
            ++sCount[s[i] - 'a'];   // 将字符串p内出现在s中的字符，以数组形式保存， 类似hashmap功能
            ++pCount[p[i] - 'a'];   // 将字符串p内出现的字符，以数组形式保存
        }
        if (sCount == pCount) {     // 当i = 0时，若s的字串与字符串p内所有字符出现的次数相同，则将index_0加入结果vector中
            ans.emplace_back(0);
        }
        // 以pLen为窗口在s内滑动
        for (sz i = 0; i < sLen - pLen; ++i) {
            // 已经处理完前一个字符，直接向后滑动一个字符
            --sCount[s[i] - 'a'];
            ++sCount[s[i + pLen] - 'a'];
            if (sCount == pCount) {
                ans.emplace_back(i + 1);    // 若s的字串与字符串p内所有字符出现的次数相同，则将index_i+1加入结果vector中(因为当前s的字串从index_i+1开始)
            }
        }
        return ans;
    }
};
}

int main(int argc, char **argv) {
    std::string s("abab"), p("ab");
    std::vector<int> ans = leetcode_cpp::Solution().findAnagrams(s, p);
    for (int &output : ans) {
        std::cout << output << " ";
    }
    std::cout << std::endl;
    return 0;
}