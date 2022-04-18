#include <bits/stdc++.h>
/*
@
projetc: leetcode
time: 2022-04-14 16:15:55
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int maximumWealth(std::vector<std::vector<int>> &accounts) {
        int ans = 0;

        for (int i=0; i<accounts.size(); ++i) {
            int sum = 0;
            for (int j=0; j<accounts[i].size(); ++j) {
                sum += accounts[i][j];
            }
            ans = std::max(ans, sum);
        }

        return ans;
    }
};
}

int main(int argc, char **argv) {
    std::vector<std::vector<int>> accounts{{1, 5}, {7, 3}, {3, 5}};

    std::cout << leetcode_cpp::Solution().maximumWealth(accounts) << '\n';

    return 0;
}
