#include <bits/stdc++.h>
#include "../lib/BinaryTree.h"

/*
@
LeetCode
time: 2022-05-05 16:22:27
author: edinw
@
*/

using namespace binary_ordinary_tree;

namespace leetcode_cpp {
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (nullptr == root) {
            return new TreeNode(val);
        }

        TreeNode *curr = root;
        while (nullptr != curr) {
            if (curr->val > val) {
                if (nullptr == curr->left) {
                    curr->left = new TreeNode(val);
                    break;
                } else {
                    curr = curr->left;
                }
            } else {
                if (nullptr == curr->right) {
                    curr->right = new TreeNode(val);
                    break;
                } else {
                    curr = curr->right;
                }
            }
        }

        return root;
    }
};
}