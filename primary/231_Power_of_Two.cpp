#include <bits/stdc++.h>

/*
@
projetc: leetcode
time: 2022-05-05 15:47:41
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }
};
}

int main(int argc, char **argv) {
    int n = 4;
    std::cout << std::boolalpha << leetcode_cpp::Solution().isPowerOfTwo(n) << std::endl;
    return 0;
}