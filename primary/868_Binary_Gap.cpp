#include <bits/stdc++.h>

/*
@
projetc: leetcode
time: 2022-04-24 14:29:03
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int binaryGap(int n) {
        int last = -1, ans = 0;
        for (int i = 0; n; ++i) {
            if (n & 1) {
                if (-1 != last) ans = std::max(ans, i - last);
                last = i;
            }
            n >>= 1;
        }

        return ans;
    }
};
}

int main(int argc, char **argv) {
    int n = 22;
    
    std::cout << leetcode_cpp::Solution().binaryGap(n) << '\n';

    return 0;
}