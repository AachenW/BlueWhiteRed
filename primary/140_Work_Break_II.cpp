#include <bits/stdc++.h>

/*
@
projetc: leetcode
time: 2022-04-20 10:11:55 
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    std::vector<std::string> wordBreak(std::string &s, std::vector<std::string> &wordDict) {
        std::unordered_set<std::string> words(wordDict.begin(), wordDict.end());
        std::unordered_map<std::string, std::vector<std::string>> mp;

        std::function<std::vector<std::string>(const std::string&)> dfs = [&] (const std::string &s) -> std::vector<std::string> {
            if (mp.find(s) != mp.end()) {
                return mp[s];
            }

            std::vector<std::string> sentences;
            if (s.empty()) {
                return {""};
            }

            for (std::string word: wordDict) {
                if (s.size() >= word.size() && s.substr(0, word.size()) == word) {
                    std::vector<std::string> subs = dfs(s.substr(word.size()));
                    for (const std::string &sub: subs) {
                        sentences.emplace_back(word + (sub.size() ? " " + sub : ""));
                    }
                }
            }

            mp[s] = sentences;
            return sentences;
        };
        
        return dfs(s);
    }
};
}

int main(int argc, char **argv) {
    std::string s{"catsanddog"};
    std::vector<std::string> wordDict{"cat", "cats", "and", "sand", "dog"};

    auto ans = leetcode_cpp::Solution().wordBreak(s, wordDict);

    for (auto &&s: ans) {
        std::cout << s << '\n';
    }
    return 0;
}
