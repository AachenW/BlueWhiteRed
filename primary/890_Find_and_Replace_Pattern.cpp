#include <bits/stdc++.h>

/*
@
projetc: leetcode
time: 2022-06-12 20:28:00 
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    std::vector<std::string> findAndReplacePattern(std::vector<std::string> words, std::string &pattern) {
        std::vector<std::string> ans;
        for (auto &word: words) 
            if (match(word, pattern) && match(pattern, word)) ans.emplace_back(word);
        return ans;
    }

private:
    bool match(std::string &word, std::string &pattern) {
        std::unordered_map<char, char> mp;
        for (int i = 0; i < word.size(); ++i) {
            char x = word[i], y = pattern[i];
            if (!mp.count(x)) mp[x] = y;
            else if (mp[x] != y) return false;
        }
        return true;
    }

};

}

int main(int argc, char **argv) {
    std::vector<std::string> words{{"abc"}, {"deq"}, {"mee"}, {"aqq"}, {"dkd"}, {"ccc"}};
    std::string pattern{"abb"};

    auto ans = leetcode_cpp::Solution().findAndReplacePattern(words, pattern);
    for (auto output: ans) std::cout << output << ",";
    std::cout << std::endl;
    return 0;
}
