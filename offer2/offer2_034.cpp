#include <vector>
#include <iostream>
#include <string>
/*
@
LeetCode 剑指offerⅡ
time: 2022-01-07 23:20:40
author: edinw
@
*/

/*
注意：本题与主站 953 题相同： https://leetcode-cn.com/problems/verifying-an-alien-dictionary/

某种外星语也使用英文小写字母，但可能顺序 order 不同。字母表的顺序（order）是一些小写字母的排列。

给定一组用外星语书写的单词 words，以及其字母表的顺序 order，只有当给定的单词在这种外星语中按字典序排列时，返回 true；否则，返回 false。
*/

namespace leetcode_cpp {
class Solution {
public:
    bool isAlienSorted(std::vector<std::string> &words, std::string order) {
        auto alienSort = [&order] (const std::string &s1, const std::string &s2) -> int {
            int length1 = s1.length(), length2 = s2.length();
            int length = length1 > length2 ? length2 : length1;
            for (int i = 0; i < length; ++i) {
                if (order.find(s1[i]) == order.find(s2[i])) {
                    continue;
                } else if (order.find(s1[i]) < order.find(s2[i])) {
                    return -1;
                } else {
                    return 1;
                }
            }
            return 0;
        };
        int wLength = words.size(); 
        for (int i = 0; i < wLength; ++i) {
            for (int j = i + 1; j < wLength; ++j) {
                if (alienSort(words[i], words[j]) > 0) {
                    return false;
                }
            }
        }
        return true;
    }
};
}

int main (int argc, char **argv) {
    std::vector<std::string> words {"hello","leetcode"};
    std::string order = "hlabcdefgijkmnopqrstuvwxyz";
    std::cout << leetcode_cpp::Solution().isAlienSorted(words, order) << std::endl;
    return 0;
}