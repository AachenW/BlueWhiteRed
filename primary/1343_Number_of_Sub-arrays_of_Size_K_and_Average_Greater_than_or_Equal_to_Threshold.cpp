#include <bits/stdc++.h>

/*
@
projetc: leetcode
time: 2022-05-04 13:16:06 
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int numOfSubarrays(std::vector<int> &nums, int k, int threshold) {
        int count = 0, sum = 0, t = k * threshold;
        int nSize = nums.size();
        for (int i = 0; i < nSize; ++i) {
            sum += nums[i];
            if (i >= k) sum -= nums[i - k];
            if (i >= k - 1 && sum >= t) ++count; 
        }

        return count;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums{2, 2, 2, 2, 5, 5, 5, 8};
    int k = 3, threshold = 4;
    std::cout << leetcode_cpp::Solution().numOfSubarrays(nums, k, threshold) << '\n';

    return 0;
}
