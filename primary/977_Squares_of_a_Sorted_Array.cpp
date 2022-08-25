#include <bits/stdc++.h>

/*
@
projetc: leetcode
time: 2022-04-19 22:25:33 
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    std::vector<int> sortedSquares(std::vector<int> &nums) {
        int nSize = nums.size();
        std::vector<int> ans(nSize);

        for (int i = 0, j = nSize - 1, pos = nSize - 1; i <= j;) {
            if (nums[i] * nums[i] > nums[j] * nums[j]) {
                ans[pos] = nums[i] * nums[i];
                ++i;
            } else {
                ans[pos] = nums[j] * nums[j];
                --j;
            }
            --pos;
        }

        return ans;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums{-7, -3, 2, 3, 11};

    auto ans = leetcode_cpp::Solution().sortedSquarts(nums);
    for (int output: ans) {
        std::cout << output << ",";
    }
    std::cout << '\n';

    return 0;
}
