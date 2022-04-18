#include <vector>
#include <string>
#include <iostream>
#include <deque>
#include "limits.h"
#include <unordered_set>
/*
@
LeetCode 热题 HOT 100
time: 2022-02-14 22:40:28
author: edinw
@
*/

/*
**  Given a string s and a dictionary of strings wordDict, return true if s can be segmented into a space-separated sequence of one or more dictionary 
**      words.
**  Note that the same word in the dictionary may be reused multiple times in the segmentation.
*/

namespace leetcode_cpp {

class Trie {
public:
    Trie *children[26];
    bool is_word;
    void insert(const std::string& word) {
        Trie *node = this;
        for (const char &c: word) {
            int ch = c - 'a';
            if (!node->children[ch]) {
                node->children[ch] = new Trie();
            }
            node = node->children[ch];
        }
        node->is_word = true;
    }
};

class Solution {
    static constexpr int charSize = 26;
public:
    bool wordBreak(std::string s, std::vector<std::string> &wordDict) {
        Trie* trie = new Trie(), *node = nullptr;
        for (const std::string &word: wordDict) {
            trie->insert(word);
        }

        int sLen = s.length();
        std::vector<int> dp(sLen + 1);
        dp[sLen] = 1;
        for (int i = sLen - 1; i >= 0; --i) {       //dp[i]表示s[i,n-1]能否由词典单词拆分
            node = trie;
            for (int j = i; j < sLen; ++j) {
                char c = s[j];
                node = node->children[c - 'a'];
                if (nullptr == node) {
                    break;
                }
                if (node->is_word && dp[j + 1]) {
                    dp[i] = 1;
                    break;
                }
            }
        }

        return dp[0];
    }
};

constexpr int Solution::charSize;

class Solution2 {
public:
    bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
        std::unordered_set<std::string> dictSet;
        for (const auto &word: wordDict) {
            dictSet.insert(word);
        }

        int sLen = s.length();
        std::vector<int> dp(sLen + 1, 0);   //dp[i]表示s中前i个字符能否由词典单词拆分
        dp[0] = 1;  // 空串可以被拆分
        for (int i = 1; i <= sLen; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (dp[j] && dictSet.count(s.substr(j, i - j))) {
                    dp[i] = 1;
                    break;
                }
            }
        }

        return dp[sLen];
    }
};

class Solution3 {
public:
    bool wordBreak(std::string s, std::vector<std::string>& wordDict) {
        int sLen = s.length();

        std::vector<int> dp(sLen + 1, 0);
        dp[0] = 1;

        for (int i = 1; i <= sLen; ++i) {
            for (auto &&word: wordDict) {
                int wLen = word.length();
                if (i >= wLen && s.substr(i - wLen, wLen) == word) {
                    dp[i] = dp[i - wLen] | dp[i];
                }
            }
        }

        return dp[sLen];
    }
};
}

int main(int argc, char **argv) {
    std::string s {"applepenapple"};
    std::vector<std::string> wordDict {"apple","pen"};
    std::cout << std::boolalpha << leetcode_cpp::Solution2().wordBreak(s, wordDict) << std::endl;
    
    return 0;
}
