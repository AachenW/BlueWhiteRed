#include <bits/stdc++.h>

/*
@
projetc: leetcode
time: 2022-02-10 22:52:00
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
private:
    std::vector<std::vector<int>> edges;
    std::vector<int> indegree;
public:
    bool canFinish(int numCourses, std::vector<std::vector<int>> &prerequisites) {
        edges.resize(numCourses);
        indegree.resize(numCourses);
        for (const auto &info: prerequisites) {
            edges[info[1]].emplace_back(info[0]);
            ++indegree[info[0]];
        }

        std::deque<int> q;
        for (int i = 0; i < numCourses; ++i) {
            if (indegree[i] == 0) {
                q.emplace_back(i);
            }
        }

        int visited = 0;
        while (!q.empty()) {
            ++visited;
            int u = q.front();
            q.pop_front();
            for (const int &v: edges[u]) {
                --indegree[v];
                if (0 == indegree[v]) {
                    q.emplace_back(v);
                }
            }
        }

        return visited == numCourses;
    }
};
}

int main(int argc, char **argv) {
    std::vector<std::vector<int>> prerequisited{{1, 0}, {0, 1}};
    int numCourse = 2;
    std::cout << std::boolalpha << leetcode_cpp::Solution().canFinish(numCourse, prerequisited) << std::endl;
    return 0;
}