#include <vector>
#include <iostream>
#include <deque>
#include "limits.h"
#include <unordered_set>
#include <queue>
#include <algorithm>
/*
@
LeetCode 剑指offerⅡ
time: 2022-01-28 20:51:30
author: edinw
@
*/

/*
**  注意：本题与主站 547 题相同： https://leetcode-cn.com/problems/number-of-provinces/
**
**  There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly 
**      with city c, then city a is connected indirectly with city c.
**  A province is a group of directly or indirectly connected cities and no other cities outside of the group.
**  You are given an n x n matrix isConnected where isConnected[i][j]=1 if the ith city and the jth city are directly connected, and isConnected[i][j]=0 **     otherwise.
**  Return the total number of provinces.
*/

namespace leetcode_cpp {
class Solution {
public:
    int findCircleNum(std::vector<std::vector<int>> &isConnected) {
        int cities = isConnected.size();
        std::vector<int> visited(cities);
        int provinces = 0;
        for (int i = 0; i < cities; ++i) {
            if (!visited[i]) {
                backtrack(isConnected, visited, cities, i);
                ++provinces;
            }
        }
        return provinces;
    }

private:
    void backtrack(std::vector<std::vector<int>> &isConnected, std::vector<int> &visited, int cities, int i) {
        for (int j = 0; j < cities; ++j) {
            if (1 == isConnected[i][j] && !visited[j]) {
                visited[j] = 1;
                backtrack(isConnected, visited, cities, j);
            }
        }
    }
};

class Solution2{
public:
    int findCircleNum(std::vector<std::vector<int>>& isConnected) {
        int cities = isConnected.size();
        int provinces = 0;
        std::vector<int> visited(cities);
        std::deque<int> queue;
        for (int i = 0; i < cities; ++i) {
            if (!visited[i]) {
                queue.emplace_back(i);
                while (!queue.empty()) {
                    int city = queue.front();
                    queue.pop_front();
                    visited[city] = 1;
                    for (int j = 0; j < cities; ++j) {
                        if (!visited[j] && isConnected[city][j]) {
                            queue.emplace_back(j);
                        }
                    }
                }
                ++provinces;
            }
        }
        return provinces;
    }
};
}

int main(int argc, char **argv) {
    std::vector<std::vector<int>> isConnected{{1, 0, 0, 1}, {0, 1, 1, 0}, {1, 0, 1, 1}};
    std::cout << leetcode_cpp::Solution2().findCircleNum(isConnected) << std::endl;
    return 0;
}