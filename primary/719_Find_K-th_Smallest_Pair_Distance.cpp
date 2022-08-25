#include <bits/stdc++.h>

/*
@
projetc: leetcode
time: 2022-06-15 21:32:45 
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int smallestDistancePair(std::vector<int> &nums, int k) {
        std::sort(nums.begin(), nums.end());
        
        int nSize = nums.size();
        int left = 0, right = nums.back() - nums.front();
        
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            int cnt = 0;
            for (int i = 0, j = 0; i < nSize; ++i) {
                while (j < nSize && nums[j] - nums[i] <= mid) ++j;
                cnt += j - i - 1;
            }

            if (cnt < k) left = mid + 1;
            else right = mid;
        }

        return left;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums {1, 6, 1};
    int k = 5;
    std::cout << leetcode_cpp::Solution().smallestDistancePair(nums, k) << std::endl;

    return 0;
}
