#include <bits/stdc++.h>

/*
@
project: Leetcode
time: 2022-03-31 22:19:19
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    bool canReach(std::vector<int>& arr, int start) {
        if (0 == arr[start]) {
            return true;
        }

        int n = arr.size();
        std::vector<int> visited(n);
        std::deque<int> que;
        que.emplace_back(start);
        visited[start] = 1;

        while (!que.empty()) {
            int curr = que.front(); que.pop_front();
            if (curr + arr[curr] < n && !visited[curr + arr[curr]]) {
                if (0 == arr[curr + arr[curr]]) {
                    return true;
                }
                que.emplace_back(curr + arr[curr]);
                visited[curr + arr[curr]] = 1;
            }
            if (curr - arr[curr] >= 0 && !visited[curr - arr[curr]]) {
                if (0 == arr[curr - arr[curr]]) {
                    return true;
                }
                que.emplace_back(curr - arr[curr]);
                visited[curr - arr[curr]] = 1;
            }
        }

        return false;
    }
};
}