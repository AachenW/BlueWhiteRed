#include <bits/stdc++.h>

/*
@
projetc: leetcode
time: 2022-05-11 18:35:28 
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int findLHS(std::vector<int> &nums) {
        std::unordered_map<int, int> mp;
        int ans = 0;
        for (int num: nums) ++mp[num];
        for (auto [key, val]: mp) {
            if (mp.count(key + 1)) {
                ans = std::max(ans, val + mp[key + 1]);
            }
        }

        return ans;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums{1, 3, 2, 2, 5, 2, 3, 7};
    std::cout << leetcode_cpp::Solution().findLHS(nums) << std::endl;
    return 0;
}
