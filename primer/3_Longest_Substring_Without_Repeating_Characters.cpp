#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <queue>
#include <ctime>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <cstdlib>
#include <numeric>

/*
@
LeetCode 精选 TOP 面试题
time: 2021-12-10 19:55:43
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        // 哈希集合，记录每个字符是否出现过
        std::unordered_set<char> occ;
        int n = s.size();
        // 右指针，初始值为-1，相当于我们在字符串的左边界的左侧，还没开始移动
        int rk = -1, ans = 0;
        // 枚举左指针的位置，初始值隐性地表示为-1
        for (int i = 0; i < n; ++i) {
            if (i != 0) {
                // 左指针向右移动一格，移除一个字符
                occ.erase(s[i - 1]);
            }
            // 当右指针rk + 1没到右边界且s[rk+1]没有重复
            while (rk + 1 < n && !occ.count(s[rk + 1])) {
                // 不断地移动右指针
                occ.insert(s[rk + 1]);
                ++rk;
            }
            // 第 i 到 rk 个字符时一个极长的无重复字符串
            ans = std::max(ans, rk - i + 1);
        }
        return ans;
    }
};
}

int main(int argc, char** argv) {
    std::string s = "abcabcbb";
    std::cout << leetcode_cpp::Solution().lengthOfLongestSubstring(s) <<std::endl;
}