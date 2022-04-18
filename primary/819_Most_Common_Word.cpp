#include <bits/stdc++.h>

/*
@
project: Leetcode
time: 2022-04-17 13:29:54
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    std::string mostCommonWord(std::string paragraph, std::vector<std::string> &banned) {
        std::unordered_map<std::string, int> cntHash;
        auto split = [&] (std::string &s) {
            int sLen = s.length();
            std::string strTemp;
            for (int i=0; i<sLen; ++i) {
                if (std::isalpha(s[i])) {
                    strTemp.push_back(std::tolower(s[i]));
                } else {
                    if (i > 0) {
                        ++cntHash[strTemp];
                        strTemp.clear();    
                    }
                    while (i<sLen && !std::isalpha(s[i])) ++i;
                    --i;
                }
            }
            if (!strTemp.empty()) ++cntHash[strTemp];
        };

        split(paragraph);

        std::unordered_set<std::string> banSet;
        for (auto &&s: banned) banSet.insert(s);
        
        int cnt = 0;
        std::string ans;
        for (auto &[key, value]: cntHash) {
            if (banSet.count(key)) continue;
            if (value > cnt) {
                cnt = value;
                ans = key;
            }
        }

        return ans;
    }
};
}


int main(int argc, char **argv) {
    std::string paragraph {"Bob. hIt, baLl"};
    std::vector<std::string> banned {"bob", "hit"};

    leetcode_cpp::Solution solu;
    std::cout << solu.mostCommonWord(paragraph, banned) << '\n';

    return 0;

}
