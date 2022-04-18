#include <bits/stdc++.h>

/*
@
project: Leetcode
time: 2022-03-30 08:40:20
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    std::vector<int> busiestServers(int k, std::vector<int>& arrival, std::vector<int>& load) {
        std::set<int> available;
        for (int i = 0; i < k; i++) {
            available.insert(i);
        }
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> busy;
        std::vector<int> requests(k);
        for (int i = 0; i < arrival.size(); i++) {
            while (!busy.empty() && busy.top().first <= arrival[i]) {
                available.insert(busy.top().second);
                busy.pop();
            }
            if (available.empty()) {
                continue;
            }
            auto p = available.lower_bound(i % k);
            if (p == available.end()) {
                p = available.begin();
            }
            requests[*p]++;
            busy.emplace(arrival[i] + load[i], *p);
            available.erase(p);
        }

        int maxRequest = *std::max_element(requests.begin(), requests.end());
        std::vector<int> ans;
        for (int i = 0; i < k; ++i) {
            if (requests[i] == maxRequest) {
                ans.emplace_back(i);
            }
        }

        return ans;
    }
};    
}