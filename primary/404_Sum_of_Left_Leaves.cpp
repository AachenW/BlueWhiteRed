#include <bits/stdc++.h>
#include "../lib/BinaryTree.h"

/*
@
projetc: leetcode
time: 2022-04-03 23:41:31
author: edinw
@
*/

using namespace binary_ordinary_tree;

namespace leetcode_cpp {
class Solution {
public:
    int sumOfLeftLeaves(TreeNode* root) {
        if (nullptr == root) {
            return 0;
        }

        auto isLeave = [] (TreeNode *node) -> bool {
            return nullptr == node->left && nullptr == node->right;
        };
        
        std::deque<TreeNode*> que{root};
        int sum = 0;
        while (!que.empty()) {
            auto node = que.front(); que.pop_front();
            if (node->left) {
                if (isLeave(node->left)) {
                    sum += node->left->val;
                } else {
                    que.emplace_back(node->left);
                }
            }
            if (node->right) {
                if (!isLeave(node->right)) {
                    que.emplace_back(node->right);
                }
            }
        }

        return sum;
    }
};
}