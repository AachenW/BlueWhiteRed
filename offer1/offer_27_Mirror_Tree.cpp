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
}