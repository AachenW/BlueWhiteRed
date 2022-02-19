#include <vector>
#include <iostream>
#include <deque>
/*
@
LeetCode 剑指offerⅡ
time: 2022-01-14 20:05:57
author: edinw
@
*/

/*
注意：本题与主站 785 题相同： https://leetcode-cn.com/problems/is-graph-bipartite/

如果图是二分图，返回 true ；否则，返回 false 。
*/

namespace leetcode_cpp {
class Solution {
private:
    static constexpr int UNCOLORED = 0;
    static constexpr int RED = 1;
    static constexpr int GREEN = 2;
    std::vector<int> color;
    bool valid;
public:
    bool isBipartite(std::vector<std::vector<int>> &graph) {
        int n = graph.size();
        valid = true;
        color.assign(n, UNCOLORED);
        for (int i = 0; i < n && valid; ++i) {
            if (color[i] == UNCOLORED) {
                backtrack(i, RED, graph);   // 入度为0的节点以红色开始
            }
        }
        return valid;
    }

    void backtrack(int node, int c, const std::vector<std::vector<int>> &graph) {
        color[node] = c;                    // 当前节点的颜色
        int cNei = (c == RED ? GREEN: RED); // 当前节点的邻居应该染的颜色
        for (const int &neighbor: graph.at(node)) {
            // 递归将未染色的邻居节点染色
            if (color.at(neighbor) == UNCOLORED) {
                backtrack(neighbor, cNei, graph);
                if (!valid) {
                    // 如果 v 被染色，并且颜色与 u 相同，那么说明给定的无向图不是二分图。我们可以直接退出遍历并返回False 作为答案。
                    return;                 
                }
            } else if (color.at(neighbor) != cNei) {
                valid = false;
                return;
            }
        }
    }
};
/*
A declaration is a definition unless
...
    it declares a static data member outside a class definition and the variable was defined within the class with the constexpr specifier (this usage is deprecated; see [depr.static_constexpr]),
*/
constexpr int Solution::UNCOLORED;
constexpr int Solution::RED;
constexpr int Solution::GREEN;


class Solution2 {
    static constexpr int UNCOLORED = 0;
    static constexpr int RED = 1;
    static constexpr int GREEN = 2;
    std::vector<int> color;
public:
    bool isBipartite(std::vector<std::vector<int>> &graph) {
        int n = graph.size();
        color.assign(n, UNCOLORED);
        for (int i = 0; i < n; ++i) {
            if (color.at(i) == UNCOLORED) {
                std::deque<int> queue;
                queue.push_back(i);
                color.at(i) = RED;
                while (!queue.empty()) {
                    int node = queue.front();
                    queue.pop_front();
                    int cNeighbor = (color.at(node) == RED ? GREEN : RED);
                    for (const int &neighbor: graph.at(node)) {
                        if (color.at(neighbor) == UNCOLORED) {
                            queue.push_back(neighbor);
                            color.at(neighbor) = cNeighbor;
                        } else if (color.at(neighbor) != cNeighbor) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};

constexpr int Solution2::UNCOLORED;
constexpr int Solution2::RED;
constexpr int Solution2::GREEN; 
}


int main(int argc, char **argv) {
    std::vector<std::vector<int>> graph {{1, 3}, {0, 2}, {1, 3}, {0, 2}};
    std::cout << std::boolalpha << leetcode_cpp::Solution2().isBipartite(graph) << std::endl;
    return 0;
}