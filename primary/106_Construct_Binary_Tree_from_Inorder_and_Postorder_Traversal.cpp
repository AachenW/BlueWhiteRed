#include <bits/stdc++.h>
#include "../lib/BinaryTree.h"

/*
@
LeetCode
time: 2022-03-24 12:55:14
author: edinw
@
*/

using namespace binary_ordinary_tree;
class Solution {
public:
    TreeNode* buildTree(std::vector<int>& inorder, std::vector<int>& postorder) {
        if (0 == inorder.size() || 0 == postorder.size()) {
            return nullptr;
        }
        int nSize = inorder.size();
        std::unordered_map<int, int> inorderIdx;
        for (int i = 0; i < nSize; ++i) {
            inorderIdx[inorder[i]] = i;
        }

        std::function<TreeNode*(int, int, int, int)> build;
        build = [&] (int inLeft, int inRight, int postLeft, int postRight) -> TreeNode* {
            if (inLeft > inRight || postLeft > postRight) {
                return nullptr;
            }

            int rootVal = postorder[postRight];
            int rootInIdx = inorderIdx[rootVal];
            TreeNode *node = new TreeNode(rootVal);

            int leftLen = rootInIdx - inLeft;
            node->left = build(inLeft, rootInIdx - 1, postLeft, postLeft + leftLen - 1);
            node->right = build(rootInIdx + 1, inRight, postLeft + leftLen, postRight - 1);

            return node;
        };

        return build(0, nSize - 1, 0, nSize - 1);
    }
};