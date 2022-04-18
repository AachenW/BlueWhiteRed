#include <bits/stdc++.h>
#include "../lib/BinaryTree.h"

using namespace binary_ordinary_tree;

/*
@
projetc: leetcode
time: 2022-04-04 19:00:24
author: edinw
@
*/

namespace leetcode_cpp {
class Solution {
    TreeNode* constructFromPrePost(std::vector<int>& preorder, std::vector<int>& postorder) {
        int nSize = preorder.size();
        std::unordered_map<int, int> postIdx;

        for (int i = 0; i < nSize; ++i) {
            postIdx[postorder[i]] = i;
        }

        std::function<TreeNode*(int, int, int, int)> build = [&] (int preLeft, int preRight, int postLeft, int postRight) -> TreeNode* {
            if (preLeft > preRight || postLeft > postRight) {
                return nullptr;
            }

            TreeNode *node = new TreeNode(preorder[preLeft]);
            if (preLeft + 1 <= preRight) {
                int leftRoot = preorder[preLeft + 1];   // 左子树根节点的值
                int leftRootInPost = postIdx[leftRoot]; // 左子树根节点的值在后序序列中的下标
                int leftLen = leftRootInPost - postLeft;
                node->left = build(preLeft + 1, preLeft + 1 + leftLen, postLeft, postLeft + leftLen);
                node->right = build(preLeft + 1 + leftLen + 1, preRight, postLeft + leftLen + 1, postRight - 1);
            }
            return node;
        };

        return build(0, nSize - 1, 0, nSize - 1);
    }
};
}