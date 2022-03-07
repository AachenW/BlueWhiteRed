#include <vector>
#include <string>
#include "limits.h"
/*
@
LeetCode 剑指offer
time: 2022-02-19 20:59:25
author: edinw
@
*/

/*
**  注意：本题与主站 8 题相同：https://leetcode-cn.com/problems/string-to-integer-atoi/
**
*/


namespace leetcode_cpp {
class Solution {
public:
    int myAtoi(std::string s) {
        int ans = 0;
        int idx = 0;
        int sLen = s.length();
        while (' ' == s[idx]) {
            ++idx;
        }

        int sign = 1;
        if ('-' == s[idx]) {
            sign = -1;
        }
        if ('+' == s[idx] || '-' == s[idx]) {
            ++idx;
        }

        while (idx < sLen && isdigit(s[idx])) {
            int r = s[idx] - '0';
            if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && r > 7)) {
                return sign > 0 ? INT_MAX : INT_MIN;
            }
            ans = ans * 10 + r;
            ++idx;
        }

        return sign > 0 ? ans : -ans;
    }
};
}

int main(int argc, char **argv) {
    std::string s{"42"};

}