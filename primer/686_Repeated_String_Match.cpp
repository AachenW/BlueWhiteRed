#include <string>
#include <vector>
#include <iostream>

/*
@
project: leetcode
time: 2021-12-22 21:01:02
author: edinw
@
*/

/*
// 给定两个字符串 a 和 b，寻找重复叠加字符串 a 的最小次数，使得字符串 b 成为叠加后的字符串 a 的子串，如果不存在则返回 -1。
// 注意：字符串 "abc" 重复叠加 0 次是 ""，重复叠加 1 次是 "abc"，重复叠加 2 次是 "abcabc"。
*/
namespace leetcode_cpp {
class Solution{
public:
    int repeatedStringMatch(std::string a, std::string b) {
        std::vector<bool> cache(26);
        for (const char &c : a) {
            cache.at(c - 'a') = true;
        }
        for (const char &c : b) {
            if (!cache.at(c - 'a')) {
                return -1;
            }
        }
        decltype(a.size()) k = b.size() / a.size();
        std::string res;
        res.reserve(b.size());
        for (decltype(k)i = 0; i < k; ++i) {
            res.append(a);
        }
        for (int i = 0; i < 3; ++i) {
            if (res.find(b) != std::string::npos) {
                return k + i;
            }
            res.append(a);
        }
        return -1;
    }
};
}

int main(int argc, char **argv) {
    std::string a = "abcd", b = "cdabcdab";
    std::cout << leetcode_cpp::Solution().repeatedStringMatch(a, b) << std::endl;
    return 0;
}