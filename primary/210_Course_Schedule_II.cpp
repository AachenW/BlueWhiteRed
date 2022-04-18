#include <bits/stdc++.h>

/*
@
project: Leetcode
time: 2022-03-24 11:34:18
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    std::vector<int> findOrder(int numCourses, std::vector<std::vector<int>>& prerequisites) {
        std::vector<std::vector<int>> graphs(numCourses);
        std::vector<int> indegree(numCourses);

        for (auto &&v: prerequisites) {
            graphs[v[1]].emplace_back(v[0]);
            ++indegree[v[0]];
        }

        std::deque<int> que;
        for (int i = 0; i < indegree.size(); ++i) {
            if (!indegree[i]) {
                que.emplace_back(i);
            }
        }

        std::vector<int> ans;
        while (!que.empty()) {
            int v = que.front(); que.pop_front();
            ans.emplace_back(v);
            for (int i = 0; i < graphs[v].size(); ++i) {
                --indegree[graphs[v][i]];
                if (!indegree[graphs[v][i]]) {
                    que.emplace_back(graphs[v][i]);
                }
            }
        }

        return ans.size() == numCourses ? ans : std::vector<int>();
    }
};
}

int main(int argc, char **argv) {
    int numCourse = 4;
    std::vector<std::vector<int>> prerequisites = {{1, 0}, {2, 0}};

    auto ans = leetcode_cpp::Solution().findOrder(numCourse, prerequisites);

    for (int num: ans) {
        std::cout << num << ",";
    }
    std::cout << std::endl;

    return 0;
}