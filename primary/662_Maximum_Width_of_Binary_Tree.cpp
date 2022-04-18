#include "../lib/BinaryTree.h"
#include <bits/stdc++.h>

/*
@
LeetCode
time: 2022-03-17 18:11:12
author: edinw
@
*/

using namespace binary_ordinary_tree;

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (nullptr == root) {
            return 0;
        }

        std::deque<std::pair<TreeNode*, long long>> que{std::make_pair(root, 1)};   // pair的第二个位置记录当前是第几个节点

        long long ans = 0;
        while (!que.empty()) {
            auto [_, left] = que.front();   // left是本层起点, ix是本层当前遍历到的节点的索引
            long long right = left;
            int qSize = que.size();
            for (int i = 0; i < qSize; ++i) {
                auto [node, idx] = que.front(); que.pop_front();
                right = idx;
                if (nullptr != node->left) {
                    que.emplace_back(std::make_pair(node->left, right * 2 - left * 2)); // 防止索引位置太大溢出
                }
                if (nullptr != node->right) {
                    que.emplace_back(std::make_pair(node->right, right * 2 + 1 - left * 2));    // 防止索引位置太大溢出
                }
            }
            ans = std::max(ans, right - left + 1);
        }

        return ans;
    }
};