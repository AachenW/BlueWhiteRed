#include <bits/stdc++.h>

/*
@
LeetCode 剑指offerⅡ
time: 2022-03-16 16:01:29
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    std::string reverseWords(std::string s) {
        int sLen = s.length();
        if (0 == sLen) {
            return "";
        }

        int start = sLen - 1, end = sLen - 1;
        std::string ans;

        while (end >= 0) {
            while (end >= 0 && ' ' == s[end]) {
                --end;
            }
            if (end < 0) {
                break;
            }
            start = end;
            while (start >= 0 && ' ' != s[start]) {
                --start;
            }

            ans += s.substr(start + 1, end - start);
            ans += " ";
            end = start;
        }

        if (!ans.empty()) {
            ans.pop_back();                         // 去除最后一个字符空格
        }
        return ans;
    }
};

class Solution2 {
    std::string reverseWords(std::string s) {
        std::stringstream ss(s);
        std::string tmp;
        std::vector<std::string> words;

        while (std::getline(ss, tmp, ' ')) {
            words.emplace_back(tmp);
        }
        
        std::string ans;
        for (auto iter = words.rbegin(); iter != words.rend(); ++iter) {
            ans += *iter;
            if (0 == (*iter).length()) {
                ans += " ";
            }
        }
        ans.pop_back();

        return ans;
    }
};
}

int main(int argc, char **argv) {
    std::string s{"  hello world  "};

    std::cout << leetcode_cpp::Solution().reverseWords(s) << std::endl;

    return 0;
}