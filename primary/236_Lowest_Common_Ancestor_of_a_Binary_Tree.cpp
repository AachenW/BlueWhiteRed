#include <vector>
#include "../lib/BinaryTree.h"
#include <functional>

/*
@
LeetCode 剑指offer
time: 2022-02-15 22:13:36
author: edinw
@
*/

/*
**  注意：本题与主站 236 题相同：https://leetcode-cn.com/problems/lowest-common-ancestor-of-a-binary-tree/
**
**  Given a binary tree, find the lowest common ancestor (LCA) of two given nodes in the tree.
**
**  According to the definition of LCA on Wikipedia: “The lowest common ancestor is defined between two nodes p and q as the lowest node in T that has 
**      both p and q as descendants (where we allow a node to be a descendant of itself).”
*/

using namespace binary_ordinary_tree;

namespace leetcode_cpp {
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        if (nullptr == root || root == p || root == q) {
            return root;
        }

        TreeNode *leftSub = lowestCommonAncestor(root->left, p, q);
        TreeNode *rightSub = lowestCommonAncestor(root->right, p, q);
        if (nullptr == leftSub && nullptr == rightSub) {
            return nullptr;
        }
        if (nullptr == leftSub) {
            return rightSub;
        }
        if (nullptr == rightSub) {
            return leftSub;
        }

        return root;
    }
};
}