#include <vector>
#include <iostream>
#include <deque>
#include "limits.h"
#include <unordered_set>

/*
@
LeetCode 剑指offerⅡ
time: 2022-01-16 22:51:48
author: edinw
@
*/

/*
** 注意：本题与主站 797 题相同：https://leetcode-cn.com/problems/all-paths-from-source-to-target/
**
** 给定一个有 n 个节点的有向无环图，用二维数组 graph 表示，请找到所有从 0 到 n-1 的路径并输出（不要求按顺序）。
** graph 的第 i 个数组中的单元都表示有向图中 i 号节点所能到达的下一些结点（译者注：有向图是有方向的，即规定了 a→b 你就不能从 b→a ），若为空，就是没有下一个节点了。
*/

namespace leetcode_cpp {
class Solution {
    std::vector<std::vector<int>> ans;
    std::vector<int> stack;
public:
    std::vector<std::vector<int>> allPathsSourceTarget(std::vector<std::vector<int>> &graph) {
        stack.emplace_back(0);
        backtrack(graph, 0, graph.size() - 1);
        return ans;
    }

private:
    void backtrack(std::vector<std::vector<int>> &graph, int x, int n) {
        if (x == n) {
            ans.emplace_back(stack);
            return;
        }
        
        for (auto &y: graph.at(x)) {
            stack.emplace_back(y);
            backtrack(graph, y, n);
            stack.pop_back();
        }
    }
};
}

