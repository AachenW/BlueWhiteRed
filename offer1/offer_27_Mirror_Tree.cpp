#include <vector>
#include <iostream>
#include <algorithm>
#include "limits.h"
#include "../lib/BinaryTree.h"

/*
@
LeetCode 剑指offer
time: 2022-02-03 19:52:12
author: edinw
@
*/

/*
**  注意：本题与主站 226 题相同：https://leetcode-cn.com/problems/invert-binary-tree/
**  Given the root of a binary tree, invert the tree, and return its root.
*/

using namespace binary_ordinary_tree;

namespace leetcode_cpp {
class Solution {
public:
    TreeNode* mirrorTree(TreeNode *root) {
        if (nullptr == root) {
            return nullptr;
        }
        TreeNode *leftNode = mirrorTree(root->left);
        TreeNode *rightNode = mirrorTree(root->right);
        root->left = rightNode;
        root->right = leftNode;
        return root;
    }
};

class Solution2 {
public:
    TreeNode* mirrorTree(TreeNode *root) {
        if (nullptr == root) {
            return nullptr;
        }

        std::deque<TreeNode*> que;
        que.emplace_back(root);

        while (!que.empty()) {
            TreeNode *node = que.front(); que.pop_front();
            if (nullptr != node->left) {
                que.emplace_back(node->left);
            }
            if (nullptr != node->right) {
                que.emplace_back(node->right);
            }
            TreeNode *tmp = node->left;
            node->left = node->right;
            node->right = tmp;
        }

        return root;
    }
};
}