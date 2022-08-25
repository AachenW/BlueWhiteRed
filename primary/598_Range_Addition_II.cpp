#include <bits/stdc++.h>

/*
@
project: leetcode
time: 2022-05-05 15:16:17
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int maxCount(int m, int n, std::vector<std::vector<int>>& ops) {
        int mina = m, minb = n;
        for (const auto& op: ops) {
            mina = std::min(mina, op[0]);
            minb = std::min(minb, op[1]);
        }
        return mina * minb;
    }
};
}

int main(int argc, char **argv) {
    int m = 3, n = 3;
    std::vector<std::vector<int>> ops{{2, 2}, {3, 3}};
    std::cout << leetcode_cpp::Solution().maxCount(m, n, ops) << std::endl;

    return 0;
}