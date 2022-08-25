#include <bits/stdc++.h>

/*
@
projetc: leetcode
time: 2022-05-11 18:04:20 
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    bool makesquare(std::vector<int> &nums) {
        if (nums.empty()) return false;
        std::vector<int> sidesLength(4, 0);
        
        int sum = std::accumulate(nums.begin(), nums.end(), 0);
        if (0 != sum % 4) return false;
        int target = sum / 4;

        std::sort(nums.begin(), nums.end(), std::greater<int>());

        std::function<int(int)> backtrack = [&] (int idx) -> int {
            if (idx == nums.size()) return sidesLength[0] == sidesLength[1] && sidesLength[1] == sidesLength[2] && sidesLength[2] == sidesLength[3];
            for (int i = 0; i < 4; ++i) {
                if (sidesLength[i] + nums[idx] > target) continue;
                sidesLength[i] += nums[idx];
                if (backtrack(idx + 1)) return true;
                sidesLength[i] -= nums[idx];
            }
            return false;
        };

        return backtrack(0);
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums{3, 3, 3, 3, 4};
    std::cout << std::boolalpha << leetcode_cpp::Solution().makesquare(nums) << std::endl;
    return 0;
}
