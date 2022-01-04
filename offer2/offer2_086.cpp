#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
/*
@
LeetCode 剑指offerⅡ
time: 2021-12-22 22:57:21
author: edinw
@
*/

namespace leetcode_cpp {
class Solution{
public:
    std::vector<std::vector<std::string>> partition(std::string s) {
        sLength = s.size();
        f.assign(sLength, std::vector<int>(sLength));

        backtrack(s, 0);
        return ret;
    } 

private:

    // 记忆化搜索中,f[i][j] = 0表示未搜索，1表示是回文串，-1表示不是回文串
    int isPalindrome(const std::string &s, int i, int j) {
        if (f[i][j]) {
            return f[i][j];
        }
        if (i >= j) {
            return f[i][j] = 1;
        }
        return f[i][j] = (s[i] == s[j] ? isPalindrome(s, i + 1, j - 1) : -1);
    }
    void backtrack(std::string &s, int i) {
        if (i == sLength) {
            ret.emplace_back(ans);
            return ;
        }
        
        for (int j = i; j < sLength; ++j) {
            // 判断s[i..j]是否为回文串
            if (isPalindrome(s, i, j) == 1) {
                ans.emplace_back(s.substr(i, j - i + 1));
                backtrack(s, j + 1);
                ans.pop_back();
            }
        }
    }

private:
    std::vector<std::vector<int>> f;
    std::vector<std::vector<std::string>> ret;
    std::vector<std::string> ans;
    int sLength;
};
}

int main(int argc, char **argv) {
    std::string s = "google";
    auto answers = leetcode_cpp::Solution().partition(s);
    for (const auto &ans : answers) {
        for (const auto &str : ans) {
            std::cout << str << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}