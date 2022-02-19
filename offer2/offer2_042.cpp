#include <vector>
#include <iostream>
#include <deque>
/*
@
LeetCode 剑指offerⅡ
time: 2022-01-14 00:03:44
author: edinw
@
*/

/*
注意：本题与主站 933 题相同： https://leetcode-cn.com/problems/number-of-recent-calls/

写一个 RecentCounter 类来计算特定时间范围内最近的请求。

请实现 RecentCounter 类：
    RecentCounter() 初始化计数器，请求数为 0 。
    int ping(int t) 在时间 t 添加一个新请求，其中 t 表示以毫秒为单位的某个时间，并返回过去 3000 毫秒内发生的所有请求数（包括新请求）。确切地说，返回在 [t-3000, t] 内发生的请求数。
    保证 每次对 ping 的调用都使用比之前更大的 t 值。
*/

namespace leetcode_cpp {
class RecentCounter {
public:
    RecentCounter() {}

    int ping(int t) {
        queue.push_back(t);
        int left = t - 3000;
        while (queue.front() < left) {
            queue.pop_front();
        }
        return queue.size();
    }

private:    
    std::deque<int> queue;
};
}

int main(int argc, char **argv) {
    leetcode_cpp::RecentCounter recentCounter;
    std::vector<int> nums {1, 100, 3001, 3002};
    for (const auto &num: nums) {
        std::cout << recentCounter.ping(num) << std::endl;
    }
    return 0;
}