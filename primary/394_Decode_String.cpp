#include <vector>
#include <iostream>
#include <algorithm>
/*
@
projetc: leetcode
time: 2022-01-31 20:32:37
author: edinw
@
*/

/*
**  Given an encoded string, return its decoded string.
**  The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is 
**      guaranteed to be a positive integer.
**  You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc.
**  Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, 
**      there will not be input like 3a or 2[4].
*/

namespace leetcode_cpp {
class Solution {
public:
    std::string decodeString(std::string s) {
        std::vector<std::string> stack;
        size_t ptr = 0;

        while (ptr < s.size()) {
            char cur = s[ptr];
            if (isdigit(cur)) {
                std::string digits = getDigits(s, ptr);
                stack.emplace_back(digits);
            } else if (isalpha(cur) || '[' == cur) {
                stack.emplace_back(std::string(1, s[ptr++]));
            } else {
                ++ptr;
                std::vector<std::string> sub;
                while ("[" != stack.back()) {
                    sub.emplace_back(stack.back());
                    stack.pop_back();
                }
                std::reverse(sub.begin(), sub.end());
                stack.pop_back();                       // 弹出"["
                int repTime = stoi(stack.back());       // 取出重复次数
                stack.pop_back();
                std::string t, o = getString(sub);      // 得到需要重复的字符串
                while (repTime--) {
                    t += o;                             // 重复字符串，得到新串
                }
                stack.emplace_back(t);                  // 压入新串，继续处理前面的重复次数
            }
        }
        return getString(stack);
    }

private:
    std::string getString(std::vector<std::string> &v) {
        std::string ret;
        for (const auto &s: v) {
            ret += s;
        }
        return ret;
    }

    std::string getDigits(std::string &s, size_t &ptr) {
        std::string ret = "";
        while (isdigit(s[ptr])) {
            ret.push_back(s[ptr++]);
        }
        return ret;
    }
};

class Solution {
public:
    std::string decodeString(std::string s) {
        std::vector<std::string> stack;
        std::string curNum = "", curStr = "";

        for (const char c: s) {
            if ('[' == c) {
                stack.emplace_back(curStr);
                stack.emplace_back(curNum);
                curStr = "";
                curNum = "";
            } else if (']' == c) {
                std::string num = stack.back();  stack.pop_back();
                std::string prevStr = stack.back(); stack.pop_back();
                curStr = prevStr + nTimesString(curStr, std::stoi(num));
            } else if (isdigit(c)) {
                curNum += c;
            } else {
                curStr += c;
            }
        }

        return curStr;
    }

private:
    std::string nTimesString(std::string s, int n){
        std::string ans = "";
        for (int i = 0; i < n; i++) {
            ans += s;
        }
        return ans;
    }
};
}

int main(int argc, char **argv) {
    std::string s {"3[a2[c]]"};
    std::cout << leetcode_cpp::Solution().decodeString(s) << std::endl;
    return 0;
}