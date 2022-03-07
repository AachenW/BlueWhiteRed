#include "../lib/BinaryTree.h"

/*
@
LeetCode 剑指offerⅡ
time: 2022-03-06 20:37:02
author: edinw
@
*/

using namespace binary_ordinary_tree;

namespace leetcode_cpp {
class Solution {
    TreeNode *resNode;
public:
    BSTIterator(TreeNode *root) {
        TreeNode *dummyNode = new TreeNode(-1);
        resNode = dummyNode;
        inorderTraverse(root);
        resNode = dummyNode;
    }

    void inorderTraverse(TreeNode *node) {
        if (nullptr == node) {
            return;
        }

        inorderTraverse(node->left);
        node->left = nullptr;
        resNode->right = node;
        resNode = node;
        inorderTraverse(node->right);
    }

    int next() {
        resNode = resNode->right;
        return resNode->val;
    }

    bool hasNext() {
        return resNode->right != nullptr;
    }
};
}
