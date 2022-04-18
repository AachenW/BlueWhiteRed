#include <bits/stdc++.h>
#include "../lib/BinaryTree.h"

/*
@
LeetCode
time: 2022-03-30 11:19:36
author: edinw
@
*/

using namespace binary_ordinary_tree;

namespace leetcode_cpp {
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        while(root){
            if(root->val == val){
                return root;
            }
            root = val < root->val ? root->left: root->right;
        }
        return nullptr;
    }
};
}
