#include <bits/stdc++.h>

/*
@
projetc: leetcode
time: 2022-04-19 19:21:49 
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    bool checkSubarraySum(std::vector<int> &nums, int k) {
        int nSize = nums.size();
        if (nSize < 2) {
            return false;
        }

        std::unordered_map<int, int> mp;
        mp[0] = -1;
        int remainder = 0;
        for (int i = 0; i < nSize; ++i) {
            remainder = (remainder + nums[i]) % k;
            if (mp.count(remainder)) {
                int prevIdx = mp[remainder];
                if (i - prevIdx >= 2) {
                    return true;
                }
            } else {
                mp[remainder] = i;
            }
        }

        return false;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums{23, 2, 6, 4, 7};
    int k = 6;

    std::cout << std::boolalpha << leetcode_cpp::Solution().checkSubarraySum(nums, k) << '\n';

    return 0;
}
