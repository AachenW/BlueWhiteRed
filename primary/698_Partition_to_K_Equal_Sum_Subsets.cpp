#include <bits/stdc++.h>

/*
@
projetc: leetcode
time: 2022-05-03 23:02:31 
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    bool backTracking(std::vector<int>& nums, std::vector<bool>& used, int k, int sum, int& target, int startIndex) {
        if (k == 0) return true;    //如果已经划分完毕了，返回true
        if (sum == target) return backTracking(nums, used, k - 1, 0, target, 0); //此次划分等于目标值
        
        for (int i = startIndex; i < nums.size(); ++i) {
            if (used[i]) continue;
            else if (sum + nums[i] > target) continue;
            sum += nums[i];
            used[i] = true;
            if (backTracking(nums, used, k, sum, target, i + 1)) return true;
            used[i] = false;
            sum -= nums[i];
        }
        return false;
    }
    bool canPartitionKSubsets(std::vector<int>& nums, int k) {
        int numsSum = std::accumulate(nums.begin(), nums.end(), 0);
        if (numsSum % k != 0) return false;
        int target = numsSum / k;
        int maxNum = *std::max_element(nums.begin(), nums.end());
        if (maxNum > target) return false;
        std::vector<bool> used(nums.size(), false); 
        return backTracking(nums, used, k, 0, target, 0);
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums{4, 3, 2, 3, 5, 2, 1};
    int k = 4;
    std::cout << std::boolalpha << leetcode_cpp::Solution().canPartitionKSubsets(nums, k) << '\n';

    return 0;
}
