#include <vector>
#include <string>
#include <unordered_set>
#include <iostream>
/*
@
project: Leetcode
time: 2022-01-05 19:09:03
author: edinw
@
*/

namespace leetcode_cpp {
class Solution{
public:
    std::string modifyString(std::string s) {
        int sLength = s.length();
        char cc = 'a';
        for (int i = 0; i < sLength; ++i) {
            if (s[i] != '?') {
                continue;
            }
            s[i] = cc;
            while (!valid(s, i)) {
                ++cc;
                if (cc > 'z') {
                    cc = 'a';
                }
                s[i] = cc;
            }
        }        
        return s;
    }

private:
    bool valid(std::string &s, int i) {
        // 和i-1相同则不合法
        if (i > 0 && s[i] == s[i - 1]) {
            return false;
        }
        // 和i+1相同则不合法
        if (i < s.size() - 1 && s[i] == s[i + 1]) {
            return false;
        }
        return true;
    }
};
}

int main(int argc, char **argv) {
    std::string  s {"??yw?ipkj?"};
    std::cout << leetcode_cpp::Solution().modifyString(s) << std::endl;
    return 0;
}