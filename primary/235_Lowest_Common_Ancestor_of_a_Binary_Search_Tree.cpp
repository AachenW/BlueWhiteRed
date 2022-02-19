#include <vector>
#include <iostream>
#include "../lib/BinaryTree.h"
/*
@
projetc: leetcode
time: 2022-02-15 22:04:42
author: edinw
@
*/

using namespace binary_ordinary_tree;

namespace leetcode_cpp {
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        TreeNode *node = root;
        while (true) {
            if (p->val < node->val && q->val < node->val) {
                node = node->left;
            } else if (p->val > node->val && q->val > node->val) {
                node = node->right;
            } else {
                break;
            }
        }

        return node;
    }
};
}