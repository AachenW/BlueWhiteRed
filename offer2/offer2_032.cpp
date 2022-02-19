#include <vector>
#include <unordered_map>
#include <iostream>

/*
@
LeetCode 剑指offerⅡ
time: 2022-01-07 21:08:23
author: edinw
@
*/

/*
注意：本题与主站 242 题相似（字母异位词定义不同）：https://leetcode-cn.com/problems/valid-anagram/

给定两个字符串 s 和 t ，编写一个函数来判断它们是不是一组变位词（字母异位词）。
注意：若 s 和 t 中每个字符出现的次数都相同且字符顺序不完全相同，则称 s 和 t 互为变位词（字母异位词）。
*/

namespace leetcode_cpp {
class Solution {
public:
    bool isAnagram(std::string s, std::string t) {
        if (s.size() != t.size()) {
            return false;
        }
        // 若s和t中每个字符出现的次数都相同且字符顺序完全相同
        if (s == t) {
            return false;
        }
        std::unordered_map<int, int> hashMap;
        // Intialize the hashmap of string s
        for (const auto &ch : s) {
            if (!hashMap.count(ch)) {
                hashMap.insert(std::make_pair(ch, 1));
            } else {
                ++hashMap.at(ch);
            }
        }

        // compare each char in string t with the hashmap of string s
        for (const auto &ch : t) {
            if (!hashMap.count(ch)) {
                return false;
            } else {
                --hashMap.at(ch);
                if (hashMap.at(ch) < 0) {
                    return false;
                }
            }
        }

        return true;
    }
};
}

int main(int argc, char **argv) {
    std::string s {"a"}, t {"a"};
    std::cout << leetcode_cpp::Solution().isAnagram(s, t) << std::endl;
    return 0;
}