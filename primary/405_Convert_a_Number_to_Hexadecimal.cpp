#include <bits/stdc++.h>

/*
@
projetc: leetcode
time: 2022-05-03 17:28:15 
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
    constexpr static char p[] = "0123456789abcdef";
public:
    std::string toHex(int num) {
        if (0 == num) return "0";
        std::string str;
        str.reserve(9);

        for (unsigned int n = num; n; n >>= 4) {
            str.push_back(p[n & 0xf]);
        }
        
        std::reverse(str.begin(), str.end());
        return str;
    }
};
}

int main(int argc, char **argv) {
    int n = -1;
    std::cout << leetcode_cpp::Solution().toHex(n) << '\n';
    return 0;
}
