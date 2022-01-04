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
time: 2021-12-09 21:09:04
author: edinw
@
*/

typedef struct Node {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
}ListNode;

namespace leetcode_cpp {
class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_map<char, int> charMap(26, 0);
        int sLength = s.size();
        int startIdx = 0, subStringLength = 0, maxSubstringLength = 0;
        for (int i = 0; i < sLength; ++i) {
            auto it = charMap.find(s[i]);
            if (it == charMap.end()) {
                startIdx = i;
                subStringLength++;
                if (subStringLength > maxSubstringLength) {
                    maxSubstringLength = subStringLength;
                }
            } else {
                subStringLength = 0;
            }
        }
        return maxSubstringLength;
    }
};
}

int main(int argc, char** argv) {
    std::string s {"pwwkew"};
    std::cout << leetcode_cpp::Solution().lengthOfLongestSubstring(s);
}