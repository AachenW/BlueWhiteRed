#include <bits/stdc++.h>

/*
@
project: leetcode
time: 2022-03-25 09:22:44
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
    static constexpr int inf = INT_MAX / 2;
public:
    int networkDelayTime(std::vector<std::vector<int>> &times, int n, int k) {
        std::vector<std::vector<int>> g(n, std::vector<int>(n, inf));
        for (auto &&t: times) {
            int x = t[0] - 1, y = t[1] - 1;
            g[x][y] = t[2];
        }

        std::vector<int> dist(n, inf);
        dist[k - 1] = 0;
        std::vector<int> used(n);

        for (int _ = 0; _ < n; ++_) {
            // 找未访问且距离起点最近的点
            int x = -1;
            int min_dist = inf;
            for (int i = 0; i < n; ++i) {
                if (!used[i] && dist[i] < min_dist) {
                    x = i;
                    min_dist = dist[i];
                }
            }
            if (-1 == x) {
                break;
            }
            // 标记为visited
            used[x] = true;
            // 更新x的邻居们
            for (int y = 0; y < n; ++y) {
                if (g[x][y] < inf) {
                    if (dist[x] + g[x][y] < dist[y]) {
                        dist[y] = dist[x] + g[x][y];
                    }
                }
            }
        }

        int ans = *max_element(dist.begin(), dist.end());
        return inf == ans ? -1 : ans;
    }
};

// 最小堆+visited+dijkstra算法
// 适应情况：稀疏图
class Solution {
    static constexpr int inf = INT_MAX / 2;
public:
    int networkDelayTime(std::vector<std::vector<int>> &times, int n, int k) {
        using pii = std::pair<int, int>;
        std::unordered_map<int, std::vector<pii>> adjvex;
        for (auto &&t: times) {
            int x = t[0] - 1, y = t[1] - 1, cost = t[2];
            adjvex[x].emplace_back(std::make_pair(y, cost));
        }

        std::vector<int> dist(n, inf);
        std::vector<int> used(n);
        dist[k - 1] = 0;

        std::priority_queue<pii, std::vector<pii>, std::greater<pii>> minHeap;
        minHeap.push({0, k - 1});

        while (!minHeap.empty()) {
            auto [d, x] = minHeap.top(); minHeap.pop();
            if (used[x]) {
                continue;
            }
            used[x] = 1;
            for (auto [y, cost]: adjvex[x]) {
                if (dist[x] + cost < dist[y]) {
                    dist[y] = dist[x] + cost;
                    minHeap.push({dist[y], y});
                }
            }
        }
        int ans = *max_element(dist.begin(), dist.end());
        return inf == ans ? -1 : ans;
    }
};

// 最小堆+dijkstra算法
// 适应情况：稀疏图
class Solution {
    static constexpr int inf = INT_MAX / 2;
public:
    int networkDelayTime(std::vector<std::vector<int>> &times, int n, int k) {
        using pii = std::pair<int, int>;
        std::unordered_map<int, std::vector<pii>> adjvex;
        for (auto &&t: times) {
            int x = t[0] - 1, y = t[1] - 1, cost = t[2];
            adjvex[x].emplace_back(std::make_pair(y, cost));
        }

        std::vector<int> dist(n, inf);
        dist[k - 1] = 0;

        std::priority_queue<pii, std::vector<pii>, std::greater<pii>> minHeap;
        minHeap.push({0, k - 1});

        while (!minHeap.empty()) {
            auto [d, x] = minHeap.top(); minHeap.pop();
            if (d >  dist[x] || inf == dist[x]) {
                continue;
            }
            for (auto [y, cost]: adjvex[x]) {
                if (dist[x] + cost < dist[y]) {
                    dist[y] = dist[x] + cost;
                    minHeap.push({dist[y], y});
                }
            }
        }
        int ans = *max_element(dist.begin(), dist.end());
        return inf == ans ? -1 : ans;
    }
};

// spfa算法--队列实现
// 适应情况：差分约束(边权值可以为负)
class Solution {
    static constexpr int inf = INT_MAX / 2;
public:
    int networkDelayTime(std::vector<std::vector<int>> &times, int n, int k) {
        using pii = std::pair<int, int>;
        std::unordered_map<int, std::vector<pii>> adjvex;
        for (auto &&t: times) {
            int x = t[0] - 1, y = t[1] - 1, cost = t[2];
            adjvex[x].emplace_back(std::make_pair(y, cost));
        }

        std::vector<int> dist(n, inf);
        dist[k - 1] = 0;
        std::vector<int> used(n);
        std::deque<int> que;

        que.emplace_back(k - 1);
        used[k - 1] = 1;
        while (!que.empty()) {
            int x = que.front(); que.pop_front();
            used[x] = 0;
            for (auto [y, cost]: adjvex[x]) {
                if (dist[x] + cost < dist[y]) {
                    dist[y] = dist[x] + cost;
                    used[y] = 1;
                    que.emplace_back(y);
                }
            }
        }
        int ans = *max_element(dist.begin(), dist.end());
        return inf == ans ? -1 : ans;
    }
};

// floyd算法
// 适应情况：多对多(边权值可以为负)
class Solution {
    static constexpr int inf = INT_MAX / 2;
public:
    int networkDelayTime(std::vector<std::vector<int>> &times, int n, int k) {
        using pii = std::pair<int, int>;
        std::vector<std::vector<int>> edge(n, std::vector<int>(n, inf));
        for (auto &&t: times) {
            int x = t[0] - 1, y = t[1] - 1, cost = t[2];
            edge[x][y] = cost;
        }

        for (int x = 0; x < n; ++x) {
            edge[x][x] = 0;
        }

        for (int mid = 0; mid < n; ++mid) {
            for (int x = 0; x < n; ++x) {
                for (int y = 0; y < n; ++y) {
                    edge[x][y] = std::min(edge[x][y], edge[x][mid] + edge[mid][y]);
                }
            }
        }

        int ans = *std::max_element(edge[k - 1].begin(), edge[k - 1].end());
        return inf == ans ? -1 : ans;
    }
};
}