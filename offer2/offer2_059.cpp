#include <iostream>
#include <deque>
#include <vector>
#include <queue>
/*
@
LeetCode 剑指offerⅡ
time: 2022-01-20 22:20:04
author: edinw
@
*/

/*
**  注意：本题与主站 729 题相同： https://leetcode-cn.com/problems/my-calendar-i/
** 
**  设计一个找到数据流中第 k 大元素的类（class）。注意是排序后的第 k 大元素，不是第 k 个不同的元素。
**  请实现 KthLargest 类：
**      KthLargest(int k, int[] nums) 使用整数 k 和整数流 nums 初始化对象。
**      int add(int val) 将 val 插入数据流 nums 后，返回当前数据流中第 k 大的元素。
*/

namespace leetcode_cpp {
class KthLargest {
    // 小根堆
    std::priority_queue<int, std::vector<int>, std::greater<int>> q;
    int k;
public:
    KthLargest(int k, std::vector<int> &nums) {
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