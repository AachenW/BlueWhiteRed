#include <vector>
#include <string>
#include <iostream>
#include <deque>
#include "../lib/BinaryTree.h"
#include <functional>

/*
@
LeetCode 剑指offer
time: 2022-02-16 19:16:56
author: edinw
@
*/

/*
**  注意：本题与主站 105 题重复：https://leetcode-cn.com/problems/construct-binary-tree-from-preorder-and-inorder-traversal/
**
**  输入某二叉树的前序遍历和中序遍历的结果，请构建该二叉树并返回其根节点。
**
**  假设输入的前序遍历和中序遍历的结果中都不含重复的数字。
*/

using namespace binary_ordinary_tree;

namespace leetcode_cpp {
class Solution {
public:
    TreeNode* buildTree(std::vector<int> &preorder, std::vector<int> &inorder) {
        std::unordered_map<int, int> idxMap;    // key preorder, value index in inorder
        int nSize = inorder.size();
        for (int i = 0; i < nSize; ++i) {
            idxMap[inorder[i]] = i;
        }

        std::function<TreeNode*(std::vector<int>&, int, int, std::vector<int>&, int, int)> backtrack;
        backtrack = [&](std::vector<int> &preorder, int preLeft, int preRight, std::vector<int> &inorder, int inLeft, int inRight) -> TreeNode* {
            if (preLeft > preRight) {
                return nullptr;
            }

            int preRoot = preLeft;
            int inRoot = idxMap[preorder[preRoot]];
            TreeNode *node = new TreeNode(preorder[preRoot]);
            int leftSubTreeLen = inRoot - inLeft;
            node->left = backtrack(preorder, preLeft + 1, preLeft + leftSubTreeLen, inorder, inLeft, inRoot - 1);
            node->right = backtrack(preorder, preLeft + 1 + leftSubTreeLen, preRight, inorder, inRoot + 1, inRight);
            return node;
        };

        return backtrack(preorder, 0, nSize - 1, inorder, 0, nSize - 1);
    }
};
}