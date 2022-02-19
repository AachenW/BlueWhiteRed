#include <vector>
#include <queue>
#include <iostream>
#include <iterator>

namespace leetcode_cpp {
class Solution {
public:
    std::vector<int> maxSlidingWindow(std::vector<int> &nums, int k) {
        int nSize = nums.size();
        std::priority_queue<std::pair<int, int>> pq;

        for (int i = 0; i < k; ++i) {
            pq.emplace(i, nums[i]);
        }

        std::vector<int> ans;
        ans.emplace_back(pq.top().second);
        for (int i = k; i < nSize; ++i) {
            pq.emplace(i, nums[i]);
            while (pq.top().first <= i - k) {
                pq.pop();
            }
            ans.emplace_back(pq.top().second);
        }

        return ans;
    }
};

class Solution2 {
public:
    std::vector<int> maxSlidingWindow(std::vector<int> &nums, int k) {
        int nSize = nums.size();
        std::deque<int> mono_queue;
        for (int i = 0; i < k; ++i) {
            while (!mono_queue.empty() && nums[mono_queue.back()] <= nums[i]) {
                mono_queue.pop_back();
            }
            mono_queue.emplace_back(i);
        }

        std::vector<int> ans {nums[mono_queue.front()]};
        for (int i = k; i < nSize; ++i) {
            while (!mono_queue.empty() && nums[mono_queue.back()] <= nums[i]) {
                mono_queue.pop_back();
            }
            mono_queue.emplace_back(i);
            while (mono_queue.front() <= i - k) {
                mono_queue.pop_front();
            }
            ans.emplace_back(nums[mono_queue.front()]);
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