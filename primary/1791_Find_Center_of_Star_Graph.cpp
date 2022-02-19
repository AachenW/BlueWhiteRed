#include <iostream>
#include <vector>
#include <deque>

/*
@
project: Leetcode
time: 2022-02-18 21:16:42
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
public:
    int findCenter(std::vector<std::vector<int>> &edges) {
        int num = edges.size() + 1;
        std::vector<int> degree(num + 1, 0);
        for (const auto edge: edges) {
            ++degree[edge[0]];
            ++degree[edge[1]];
        }

        for (int i = 1; ; ++i) {
            if (degree[i] == num - 1) {
                return i;
            }
        }
        return -1;
    }
};
}

int main(int argc, char **argv) {
    std::vector<std::vector<int>> edges{{1, 2}, {2, 3}, {4, 2}};
    std::cout << leetcode_cpp::Solution().findCenter(edges) << std::endl;

    return 0;
}