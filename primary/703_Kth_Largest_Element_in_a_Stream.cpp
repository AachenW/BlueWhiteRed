#include <priority_queue>

/*
@
LeetCode 剑指offerⅡ
time: 2022-03-06 22:19:30
author: edinw
@
*/

namespace leetcode_cpp {
class KthLargest {
    // x小根堆
    std::priority_queue<int, std::vector<int>, std::greater<int>> q;
    int k;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for (const auto &num: nums) {
            add(num);
        }
    }
    
    int add(int val) {
        q.emplace(val);
        if (q.size() > k) {
            q.pop();
        }
        return q.top();
    }
};
}
