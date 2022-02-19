#include <vector>
#include <unordered_map>
#include <iostream>
#include <functional>
#include <numeric>
#include <array>
#include <algorithm>
/*
@
LeetCode 剑指offerⅡ
time: 2022-01-07 22:03:35
author: edinw
@
*/

/*
注意：本题与主站 49 题相同： https://leetcode-cn.com/problems/group-anagrams/

给定一个字符串数组 strs ，将 变位词 组合在一起。 可以按任意顺序返回结果列表。

注意：若两个字符串中每个字符出现的次数都相同，则称它们互为变位词。
*/

namespace leetcode_cpp {
class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        // 自定义对 array<int, 26> 类型的哈希函数
        auto arrayHash = [fn = std::hash<int>{}] (const std::array<int, 26> &arr) -> size_t {
            return std::accumulate(arr.begin(), arr.end(), 0u, [&](size_t acc, int num) {
                return (acc << 1) ^ fn(num);
            });
        };
        std::unordered_map<std::array<int, 26>, std::vector<std::string>, decltype(arrayHash)> mp(0, arrayHash);
        for (const auto &str : strs) {
            std::array<int, 26> counts {};
            int sLength = str.length();
            for (int i = 0; i < sLength; ++i) {
                ++counts[str[i] - 'a'];
            }
            mp[counts].emplace_back(str);
        }
        std::vector<std::vector<std::string>> ans;
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            ans.emplace_back(it->second);
        }
        return ans;
    }
};

class Solution2 {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::unordered_map<std::string, std::vector<std::string>> hashMap;
        for (const auto &str : strs) {
            std::string key = str;
            sort(key.begin(), key.end());
            hashMap[key].emplace_back(str);
        }
        std::vector<std::vector<std::string>> ans;
        for (auto it = hashMap.begin(); it != hashMap.end(); ++it) {
            ans.emplace_back(it->second);
        }
        return ans;
    }
};
}

int main (int argc, char **argv) {
    std::vector<std::string> strs {"eat", "tea", "tan", "ate", "nat", "bat"};
    auto ansArr = leetcode_cpp::Solution2().groupAnagrams(strs);
    for (const auto &arr : ansArr) {
        for (const auto &str : arr) {
            std::cout << str << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}