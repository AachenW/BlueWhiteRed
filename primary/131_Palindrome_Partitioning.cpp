#include <string>
#include <vector>
#include <string>
#include <functional>

/*
@
LeetCode 剑指offerII
time: 2022-03-07 14:08:42
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    std::vector<std::vector<std::string>> partition(std::string s) {
        int sLen = s.length();
        std::vector<std::vector<int>> dp(sLen, std::vector<int>(sLen, 1));
        std::vector<std::vector<std::string>> ans;
        std::vector<std::string> candidates;

        for (int i = sLen - 1; i >= 0; --i) {
            for (int j = i + 1; j < sLen; ++j) {
                dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
            }
        }

        std::function<void(int)> backtrack = [&](int idx) {
            if (idx == sLen) {
                ans.emplace_back(candidates);
                return;
            }

            for (int i = idx; i < sLen; ++i) {
                // // 判断s[i..j]是否为回文串
                if (1 == dp[idx][i]) {
                    candidates.emplace_back(s.substr(idx, i - idx + 1));   // 如果是回文串，则将子串加入到ans中
                    backtrack(i + 1);   // 跳到s[j+1]，继续搜索
                    candidates.pop_back(); // 回溯
                }
            }
        };

        backtrack(0);
        return ans;
    }
};

class Solution2 {
public:
    std::vector<std::vector<std::string>> partition(std::string s) {
        std::vector<std::vector<std::string>> ans;
        std::vector<std::string> candidates;
        int sLen = s.length();

        std::function<void(int)> backtrack = [&](int idx) {
            if (idx == sLen) {
                ans.emplace_back(candidates);
                return;
            }

            for (int i = idx; i < sLen; ++i) {
                if (isPalindrom(s, idx, i)) {
                    candidates.emplace_back(s.substr(idx, i - idx + 1));
                    backtrack(i + 1);
                    candidates.pop_back();
                }
            }
        };

        backtrack(0);

        return ans;
    }

private:
    bool isPalindrom(std::string &s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) {
                return false;
            } else {
                ++left;
                --right;
            }
        }
        return true;
    }
};
}