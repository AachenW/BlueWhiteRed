#include <bits/stdc++.h>

/*
@
projetc: leetcode
time: 2022-01-31 08:48:52
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    std::vector<std::string> uncommonFromSentences(std::string s1, std::string s2) {
        std::unordered_map<std::string, int> hashMap;
        std::vector<std::string> strs;
        std::string temp;
        for (const auto &ch: s1) {
            if (' ' == ch) {
                ++hashMap[temp];
                temp.clear();
            } else {
                temp.push_back(ch);
            }
        }
        if (!temp.empty()) {
            ++hashMap[temp];
            temp.clear();
        }


        for (const auto &ch: s2) {
            if (' ' == ch) {
                ++hashMap[temp];
                temp.clear();
            } else {
                temp.push_back(ch);
            }
        }
        if (!temp.empty()) {
            ++hashMap[temp];
            temp.clear();
        }

        std::vector<std::string> ans;
        for (const auto &pair: hashMap) {
            if (1 == pair.second) {
                ans.emplace_back(pair.first);
            } 
        }
        return ans;
    }
};
}

int main(int argc, char **argv) {
    std::string s1{"apple apple"};
    std::string s2{"banana"};
    auto ans = leetcode_cpp::Solution().uncommonFromSentences(s1, s2);
    for (const auto &str: ans) {
        std::cout << str << " ";
    }
    std::cout << std::endl;
    return 0;
}