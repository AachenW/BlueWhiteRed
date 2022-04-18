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
        int rk = 0, ans = 0;
        // 枚举左指针的位置，初始值隐性地表示为-1
        for (int i = 0; i < n; ++i) {
            if (i != 0) {
                // 左指针向右移动一格，移除一个字符
                occ.erase(s[i - 1]);
            }
            // 当右指针rk + 1没到右边界且s[rk+1]没有重复
            while (rk < n && !occ.count(s[rk])) {
                // 不断地移动右指针
                occ.insert(s[rk]);
                ++rk;
            }
            // 第 i 到 rk 个字符时一个极长的无重复字符串
            ans = std::max(ans, rk - i);
        }
        return ans;
    }
};

class Solution2 {
public:
    int lengthOfLongestSubstring(std::string s) {
        int sLen = s.length();
        if (0 == sLen) {
            return 0;
        }
        std::unordered_map<char, int> idxMap;
        int ans = 0, dp = 0;
        for (int i = 0; i < sLen; ++i) {
            int index = idxMap.find(s[i]) != idxMap.end() ? idxMap[s[i]] : -1;
            idxMap[s[i]] = i;
            if (dp < i - index) {
                dp += 1;
            } else {
                dp = i - index;
            }
            ans = std::max(ans, dp);
        }
        return ans;
    }
};

class Solution3 {
public:
    int lengthOfLongestSubstring(std::string s) {
        int sLen = s.length();
        if (0 == sLen) {
            return 0;
        }
        // 哈希表统计字符 s[j] 最后一次出现的索引
        std::unordered_map<char, int> cntMap;
        int lo = -1, maxLen = 0;
        for (int hi = 0; hi < sLen; ++hi) {
            if (cntMap.count(s[hi])) {
                lo = std::max(lo, cntMap[s[hi]]);   // 根据上轮左指针 lo 和 cntMap[s[hi]] ，每轮更新左边界 i ，保证区间 [i + 1, j] 内无重复字符且最大。
            }
            cntMap[s[hi]] = hi;
            maxLen = std::max(maxLen, hi - lo);
        }
        return maxLen;
    }
};
}

int main(int argc, char** argv) {
    std::string s = "abcabcbb";
    std::cout << leetcode_cpp::Solution().lengthOfLongestSubstring(s) <<std::endl;
}