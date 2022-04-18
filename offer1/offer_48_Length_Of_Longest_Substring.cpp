#include <vector>
#include <iostream>
#include <unordered_set>
#include <unordered_map>
/*
@
LeetCode 剑指offer
time: 2022-02-06 19:49:52
author: edinw
@
*/

/*
**  注意：本题与主站 3 题相同：https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
**
**  请从字符串中找出一个最长的不包含重复字符的子字符串，计算该最长子字符串的长度。
*/

namespace leetcode_cpp {
class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        std::unordered_set<int> cntMap;
        int sLen = s.length();
        int maxLen = 0, start = 0;
        int hi = 0;
        for (int i = 0; i < sLen; ++i) {
            if (0 != i) {
                cntMap.erase(s[i - 1]);
            }
            while (!cntMap.count(s[hi]) && hi < sLen) {
                cntMap.insert(s[hi++]);
            }
            
            maxLen = std::max(maxLen, hi - i);
        }
        return maxLen;
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
        // dp[j] 代表以字符 s[j] 为结尾的 “最长不重复子字符串” 的长度
        int ans = 0, dp = 0;
        for (int i = 0; i < sLen; ++i) {
            int index = idxMap.find(s[i]) != idxMap.end() ? idxMap[s[i]] : -1;
            idxMap[s[i]] = i;
            // 当 dp[j - 1] < j - i，说明字符 s[i] 在子字符串 dp[j−1] 区间之外，则 dp[j] = dp[j - 1] + 1
            if (dp < i - index) {
                dp += 1;
            } 
            // 当 dp[j−1]≥j−i ，说明字符 s[i] 在子字符串 dp[j−1] 区间之中 ，则 dp[j] 的左边界由 s[i] 决定，即 dp[j] = j - i
            else {
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

int main(int argc, char **argv) {
    std::string s{" "};
    std::cout << leetcode_cpp::Solution2().lengthOfLongestSubstring(s) << std::endl;
    return 0;
}