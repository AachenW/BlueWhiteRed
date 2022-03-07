#include <deque>

/*
@
project: leetcode
time: 2022-03-05 15:53:14
author: edinw
@
*/

namespace leetcode_cpp {
class RecentCounter {
public:
    RecentCounter {}

    int ping(int t) {
        que.emplace_back(t);
        int left = t - 3000;
        while (que.front() < left) {
            que.pop_front();
        }
        return que.size();
    }

private:
    std::deque<int> que;
};
}

