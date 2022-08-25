#include <bits/stdc++.h>

/*
@
projetc: leetcode
time: 2022-05-03 12:56:25 
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    std::vector<int> findDuplicates(std::vector<int> &nums) {
        int nSize = nums.size();
        std::vector<int> ans;
        
        for (int i = 0; i < nSize; ++i) {
            int idx = std::abs(nums[i]) - 1;
            if (nums[idx] < 0) ans.emplace_back(idx + 1);
            nums[idx] = -nums[idx];
        }

        return ans;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums{4, 3, 2, 7, 8, 2, 3, 1};

    auto ans = leetcode_cpp::Solution().findDuplicates(nums);
    for (int num: ans) {
        std::cout << num << ",";
    }
    std::cout << '\n';

    return 0;
}
