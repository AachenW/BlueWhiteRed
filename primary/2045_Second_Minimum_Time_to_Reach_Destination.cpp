#include <vector>
#include <iostream>
#include <deque>
#include "limits.h"
/*
@
project: Leetcode
time: 2022-01-24 18:54:04
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int secondMinimum(int n, std::vector<std::vector<int>> &edges, int time, int change) {
        std::vector<std::vector<int>> graph(n + 1);
        for (const auto &e: edges) {
            graph[e[0]].emplace_back(e[1]);
            graph[e[1]].emplace_back(e[0]);
        }

        // path[i][0]表示从1到i的最短路长度，path[i][1]表示从1到i的严格次短路长度
        std::vector<std::vector<int>> path(n + 1, std::vector<int>(2, INT_MAX));
        path[1][0] = 0;
        std::deque<std::pair<int, int>> queue;
        queue.emplace_back(std::make_pair(1, 0));
        while (path[n][1] == INT_MAX) {
            auto [cur, len] = queue.front();
            queue.pop_front();
            for (const auto& next: graph[cur]) {
                if (len + 1 < path[next][0]) {
                    path[next][0] = len + 1;
                    // 这里更新完最短总路程后，为什么不进行比较原path[next][0]与path[next][1]的大小，从而更新次短总路程？
                    // 答：最短总路程总是先到达的，故不可能存在次短总路程先到达，然后最短总路程才到达
                    queue.emplace_back(std::make_pair(next, len + 1));
                } else if (len + 1 > path[next][0] && len + 1 < path[next][1]) {
                    path[next][1] = len + 1;
                    queue.emplace_back(std::make_pair(next, len + 1));
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < path[n][1]; ++i) {
            if (ans % (2 * change) >= change) {
                ans = ans + (2 * change - ans % (2 * change));
            }
            ans += time;
        }
        return ans;
    }
};
}


int main(int argc, char **argv) {
    std::vector<std::vector<int>> edges{{1, 2}, {1, 3}, {1, 4}, {3, 4}, {4, 5}};
    int n = 5, time = 3, change = 5;
    std::cout << leetcode_cpp::Solution().secondMinimum(n, edges, time, change) << std::endl;
    return 0;
}