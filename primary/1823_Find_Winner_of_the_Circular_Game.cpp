#include <bits/stdc++.h>

/*
@
projetc: leetcode
time: 2022-05-04 10:51:14 
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int findTheWinner(int n, int k) {
        int ans = 0;
        for (int i = 2; i < n + 1; ++i) ans = (ans + k) % i;
        return ans + 1;
    }
};
}

int main(int argc, char **argv) {
    int n = 5, k = 2;
    std::cout << leetcode_cpp::Solution().findTheWinner(n, k) << '\n';
    return 0;
}
