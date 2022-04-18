#include <bits/stdc++.h>

/*
@
LeetCode
time: 2022-04-03 21:06:49
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    std::vector<int> partitionLabels(std::string s) {
        std::vector<int> lastIdx(26);
        int sLen = s.length();
        for (int i = 0; i < sLen; ++i) {
            lastIdx[s[i] - 'a'] = i;
        }

        std::vector<int> ans;
        int start = 0, end = 0;
        // 从左到右遍历字符串，遍历的同时维护当前片段的开始下标start和结束下标end，初始时 start = end = 0。
        for (int i = 0; i < sLen; ++i) {
            // 对于每个访问到的字母c，得到当前字母的最后一次出现的下标位置endc，则当前片段的结束下标一定不会小于endc，因此令end=max(end,endc)。
            end = std::max(end, lastIdx[s[i] - 'a']);
            // 当访问到下标end 时，当前片段访问结束，当前片段的下标范围是[start,end]，长度为end−start+1，将当前片段的长度添加到返回值，然后令 
            // start=end+1，继续寻找下一个片段。
            if (i == end) {
                ans.emplace_back(end - start + 1);
                start = end + 1;
            }
        }

        return ans;
    }
};
}