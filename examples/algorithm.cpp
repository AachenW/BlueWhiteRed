#include <bits/stdc++.h>

std::vector<long long> dijkstra(std::vector<std::vector<std::pair<int, int>>> &adj, int s) {
    int n = adj.size();
    std::priority_queue<std::pair<long long, int>, std::vector<std::pair<long long, int>>, std::greater<>> pq;
    std::vector<long long> dis(n, INF);
    dis[s] = 0;
    pq.emplace(0, s);
    
    while (!pq.empty()) {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dis[u])
            continue;
        
        for (auto [v, w] : adj[u]) {
            if (d + w < dis[v]) {
                dis[v] = d + w;
                pq.emplace(dis[v], v);
            }
        }
    }
    
    return dis;
}

int lowerBound(std::vector<int> &nums, int target) {
    int lo = 0, hi = nums.size();

    while (lo < hi) {
        int mid = lo + ((hi - lo) >> 1);
        if (nums[mid] >= target) {
            hi = mid;
        } else {
            lo = mid + 1;
        }
    }
    
    return lo;
}

int uppeBound(std::vector<int> &nums, int target) {
    int lo = 0, hi = nums.size();

    while (lo < hi) {
        int mid = lo + ((hi - lo) >> 1);
        if (nums[mid] <= target) {
            lo = mid + 1;
        } else {
            hi = mid;
        }
    }
    
    return lo;
}