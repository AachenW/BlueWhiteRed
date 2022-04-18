#include <bits/stdc++.h>
#include "../lib/BinaryTree.h"
/*
@
LeetCode
time: 2022-03-20 15:52:27
author: edinw
@
*/

using namespace binary_ordinary_tree;

namespace leetcode_cpp {
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (nullptr == root) {
            return 0;
        }
        if (nullptr == root->left && nullptr == root->right) {
            return 1;
        }

        int ans = INT_MAX;
        if (nullptr != root->left) {
            ans = std::min(ans, minDepth(root->left));
        }
        if (nullptr != root->right) {
            ans = std::min(ans, minDepth(root->right));
        }

        return ans + 1;
    }
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (nullptr == root) {
            return 0;
        }
        
        std::deque<std::pair<TreeNode*, int>> que;
        que.emplace_back(root, 1);

        while (!que.empty()) {
            auto [node, depth] = que.front(); que.pop_front();
            if (nullptr == node->left && nullptr == node->right) {
                return depth;
            }
            if (nullptr != node->left) {
                que.emplace_back(node->left, depth + 1);
            }
            if (nullptr != node->right) {
                que.emplace_back(node->right, depth + 1);
            }
        }

        return 0;
    }
};
}