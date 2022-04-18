#include <bits/stdc++.h>

namespace leetcode_cpp {
class Solution {
public:
    int numRabbits(std::vector<int> &answers) {
        std::unordered_map<int, int> c;
        for (int i : answers) {
            ++c[i];
        }
        // If x+1 rabbits have same color, then we get x+1 rabbits who all answer x.
        // now n rabbits answer x.
        // If n % (x + 1) == 0, we need n / (x + 1) groups of x + 1 rabbits.
        // If n % (x + 1) != 0, we need n / (x + 1) + 1 groups of x + 1 rabbits.
        // the number of groups is math.ceil(n / (x + 1)) and it equals to (n + x) / (x + 1) , which is more elegant.
        int ans = 0;
        for (auto i: c) {
            ans += (i.first + i.second) / (i.first + 1) * (i.first + 1);
        }

        return ans;
    }
};
}