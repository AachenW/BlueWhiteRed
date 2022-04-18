#include <bits/stdc++.h>

namespace leetcode_cpp {
class Solution {
public:
    std::vector<int> findSubstring(std::string s, std::vector<std::string> &words) {
        std::unordered_map<std::string, int> counts;    // record the expected times of each word
        std::vector<int> ans;
        for (std::string word: words) {
            ++counts[word];
        } 

        int sLen = s.length(), num = words.size();
        if (0 == sLen || 0 == num) {
            return ans;
        }
        int len = words[0].length();
        // we check for every possible position of i
        for (int i = 0; i < sLen - num * len + 1; ++i) {
            std::unordered_map<std::string, int> seen;  // record the times we have seen
            int j = 0;
            for (; j < num; ++j) {
                std::string word = s.substr(i + j * len, len);
                if (counts.find(word) != counts.end()) { 
                    ++seen[word];
                    if (seen[word] > counts[word]) {
                        break;  // the times of some word is large than its expected times, we stop the check
                    }
                } else {
                    break;  // Once we meet an unexpected word, we stop the check.
                }
            }
            if (j == num) {
                ans.emplace_back(i);    // If we finish the check successfully, push i to the result indexes.
            }
        }

        return ans;
    }
};
}