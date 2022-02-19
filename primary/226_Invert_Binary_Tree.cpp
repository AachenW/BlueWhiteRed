#include <vector>
#include <iostream>
#include "../lib/BinaryTree.h"
/*
@
projetc: leetcode
time: 2022-02-03 20:03:18
author: edinw
@
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