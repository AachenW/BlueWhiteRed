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

class Solution2 {
public:
    std::vector<int> findSubstring(std::string &s, std::vector<std::string> &words) {
        std::vector<int> res;
        int m = words.size(), n = words[0].size(), ls = s.size();
        for (int i = 0; i < n && i + m * n <= ls; ++i) {
            std::unordered_map<std::string, int> differ;
            for (int j = 0; j < m; ++j) {
                ++differ[s.substr(i + j * n, n)];
            }

            for (std::string &word: words) {
                if (--differ[word] == 0) {
                    differ.erase(word);
                }
            }

            for (int start = i; start < ls - m * n + 1; start += n) {
                if (start != i) {
                    std::string word = s.substr(start + (m - 1) * n, n);
                    if (++differ[word] == 0) {
                        differ.erase(word);
                    }

                    word = s.substr(start - n, n);
                    if (--differ[word] == 0) {
                        differ.erase(word);
                    }
                }
                if (differ.empty()) {
                    res.emplace_back(start);
                }
            }
        }
        return res;
    }
};
}

int main(int argc, char **argv) {
    std::string s{"barfoothefoobarman"};
    std::vector<std::string> words {"foo", "bar"};

    auto ans = leetcode_cpp::Solution().findSubstring(s, words);
    for (const auto &output: ans) std::cout << output << ",";
    std::cout << std::endl;

    return 0;
}
