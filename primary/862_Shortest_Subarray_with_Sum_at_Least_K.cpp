#include <bits/stdc++.h>

namespace leetcode_cpp {
class Solution {
public:
    int shortestSubarray(std::vector<int>& nums, int k) {
        int nSize = nums.size(), res = nSize + 1;
        std::deque<int> que;
        std::vector<long long> prefix(nSize + 1);   // prefix[j] - prefix[i] represents the sum of subarray nums[i] ~ nums[j-1]

        for (int i = 1; i <= nSize; ++i) {
            prefix[i] = prefix[i - 1] + nums[i - 1];    // calculate prefix sum of list nums
        }

        for (int i = 0; i < nSize + 1; ++i) {    
            // For every prefix[i], we will compare prefix[i] - prefix[d[0]] with K.
            while (!que.empty() && prefix[i] - prefix[que.front()] >= k) {
                res = std::min(res, i - que.front()); que.pop_front();
            }
            // Deque que will keep indexes of increasing B[i].
            while (!que.empty() && prefix[i] <= prefix[que.back()]) {
                que.pop_back();
            }
            que.emplace_back(i);
        }

        return res <= nSize ? res : -1;
    }
};
}