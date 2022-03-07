#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <algorithm>
/*
@
project: leetcode
time: 2022-03-05 12:19:21
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> &strs) {
        std::unordered_map<std::string, std::vector<std::string>> mp;
        for (auto &&str: strs) {
            std::string tmp = str;
            std::sort(tmp.begin(), tmp.end());
            mp[tmp].emplace_back(str);
        }
        
        std::vector<std::vector<std::string>> ans;
        for (auto &&p: mp) {
            ans.emplace_back(p.second);
        }
        return ans;
    }
};
}

int main(int argc, char **argv) {
    std::vector<std::string> strs{"eat","tea","tan","ate","nat","bat"};

    auto answers = leetcode_cpp::Solution().groupAnagrams(strs);

    for (auto &&ans: answers) {
        for (auto &&str: ans) {
            std::cout << str << ",";
        }
        std::cout << std::endl;
    }

    return 0;
}
