#include <bits/stdc++.h>

/*
@
LeetCode
time: 2022-03-25 10:29:57
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int lengthOfLongestSubstringKDistinct(std::string s, int k) {
        int sLen = s.length(), ans = 0;
        std::unordered_map<char, int> hashMap;

        for (int i = 0, j = 0; j < sLen; ++j) {
            ++hashMap[s[j]];
            while (i < sLen && hashMap.size() > k) {
                --hashMap[s[i]];
                if (hashMap.count(s[i]) && 0 == hashMap[s[i]]) {
                    hashMap.erase(s[i]);
                    ++i;
                }
            }
            ans = std::max(ans, j - i + 1);
        }

        return ans;
    }
};
}