#include <bits/stdc++.h>
#include "../lib/BinaryTree.h"

/*
@
project: Leetcode
time: 2022-03-29 20:02:37
author: edinw
@
*/

using namespace binary_ordinary_tree;

namespace leetcode_cpp {
class Solution {
public:
    int deepestLeavesSum(TreeNode *root) {
        int ans = 0, maxDepth = 0;
        std::function<void(TreeNode*, int)> backtrack = [&] (TreeNode *root, int depth) {
            if (nullptr == root) {
                return;
            }

            if (depth > maxDepth) {
                maxDepth = depth;
                ans = root->val;
            } else if (depth == maxDepth) {
                ans += root->val;
            }

            backtrack(root->left, depth + 1);
            backtrack(root->right, depth + 1);
        };

        backtrack(root, 0);

        return ans;
    }
};

class Solution2 {
public:
    int deepestLeaveSum(TreeNode *root) {
        int ans = 0, maxDepth = 0;
        using pti = std::pair<TreeNode*, int>;
        std::deque<pti> que;
        que.emplace_back(std::make_pair(root, 0));

        while (!que.empty()) {
            auto [node, depth] = que.front(); que.pop_front();
            if (depth > maxDepth) {
                maxDepth = depth;
                ans = node->val;
            } else if (depth == maxDepth) {
                ans += node->val;
            }

            if (nullptr != node->left) {
                que.emplace_back(std::make_pair(node->left, depth + 1));
            }
            if (nullptr != node->right) {
                que.emplace_back(std::make_pair(node->right, depth + 1));
            }
        }

        return ans;
    }
};
}