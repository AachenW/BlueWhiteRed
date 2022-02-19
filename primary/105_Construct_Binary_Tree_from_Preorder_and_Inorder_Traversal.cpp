#include <vector>
#include <iostream>
#include <algorithm>
#include "../lib/BinaryTree.h"
/*
@
LeetCode 剑指offer
time: 2022-02-14 22:15:07
author: edinw
@
*/

using namespace binary_ordinary_tree;

namespace leetcode_cpp {
class Solution {
public:
    TreeNode* buildTree(std::vector<int> &preorder, std::vector<int> &inorder) {
        int nSize = preorder.size();

        for (int i = 0; i < nSize; ++i) {
            idxMap[inorder[i]] = i;
        }

        return buildTree(preorder, 0, nSize - 1, inorder, 0, nSize - 1);
    }

private:
    TreeNode* buildTree(std::vector<int> &preorder, int preorderLeft, int preorderRight,
                               std::vector<int> &inorder, int inorderLeft, int inorderRight) {
        if (preorderLeft > preorderRight) {
            return nullptr;
        }

        int preorderRoot = preorderLeft;
        int inorderRoot = idxMap[preorder[preorderRoot]];

        TreeNode *root = new TreeNode(preorder[preorderRoot]);
        int sizeLeftTree = inorderRoot - inorderLeft;
        root->left = buildTree(preorder, preorderLeft + 1, preorderLeft + sizeLeftTree, inorder, inorderLeft, inorderLeft + sizeLeftTree);
        root->right = buildTree(preorder, preorderLeft + sizeLeftTree + 1, preorderRight, inorder, inorderRoot + 1, inorderRight);

        return root;
    }

private:
    std::unordered_map<int, int> idxMap;
};
}