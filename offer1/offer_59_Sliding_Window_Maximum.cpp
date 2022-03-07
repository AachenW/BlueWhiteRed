#include <vector>
#include <iostream>
#include <algorithm>
#include "../lib/BinaryTree.h"
#include <iterator>
/*
@
LeetCode 剑指offer
time: 2022-02-19 21:42:14
author: edinw
@
*/

/*
**  注意：本题与主站 239 题相同：https://leetcode-cn.com/problems/sliding-window-maximum/
**
**  You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You 
**      can only see the k numbers in the window. Each time the sliding window moves right by one position.
**
**  Return the max sliding window.
*/

namespace leetcode_cpp {
class Solution {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        int nSize = nums.size();
        if (0 == nSize) {
            return {};
        }
        std::deque<int> mono_stack;
        for (int i = 0; i < k; ++i) {
            while (!mono_stack.empty() && nums[mono_stack.back()] <= nums[i]) {
                mono_stack.pop_back();
            }
            mono_stack.emplace_back(i);
        }

        std::vector<int> ans {nums[mono_stack.front()]};
        for (int i = k; i < nSize; ++i) {
            while (!mono_stack.empty() && nums[mono_stack.back()] <= nums[i]) {
                mono_stack.pop_back();
            }
            mono_stack.emplace_back(i);
            while (!mono_stack.empty() && mono_stack.front() <= i - k) {
                mono_stack.pop_front();
            }
            ans.emplace_back(nums[mono_stack.front()]);
        }

        return ans;
    }
};

class Solution2 {
public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k) {
        int nSize = nums.size();
        if (0 == nSize) {
            return {};
        }
        using pii = std::pair<int, int>;
        auto cmp = [](const pii &p1, const pii &p2) {
            return p1.first < p2.first;
        };
        std::priority_queue<pii, std::vector<pii>, decltype(cmp)> pq(cmp);

        for (int i = 0; i < k; ++i) {
            pq.emplace(nums[i], i);
        }

        std::vector<int> ans {pq.top().first};
        for (int i = k; i < nSize; ++i) {
            pq.emplace(nums[i], i);
            while (pq.top().second <= i - k) {
                pq.pop();   // 延迟删除
            }
            ans.emplace_back(pq.top().first);
        }

        return ans;
    }
};
}

int main(int argc, char **argv) {
    std::vector<int> nums {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    auto ans = leetcode_cpp::Solution2().maxSlidingWindow(nums, k);
    
    std::ostream_iterator<int> oIter(std::cout, ", ");
    std::copy(ans.begin(), ans.end(), oIter);

    return 0;
}