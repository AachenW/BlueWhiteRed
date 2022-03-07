#include "../lib/BinaryTree.h"

/*
@
LeetCode 剑指offerⅡ
time: 2022-03-06 20:30:43
author: edinw
@
*/

using namespace binary_ordinary_tree;

namespace leetcode_cpp {
class Solution {
    int prefix;
public:
    TreeNode* convertBST(TreeNode *root) {
        if (nullptr == root) {
            return nullptr;
        }
        
        convertBST(root->right);
        
        prefix += root->val;
        root->val = prefix;

        convertBST(root->left);

        return root;
    }
};
}

