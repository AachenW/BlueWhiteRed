#include <vector>
#include <iostream>
#include <algorithm>
#include "../lib/BinaryTree.h"
/*
@
LeetCode 剑指offer
time: 2022-02-14 21:18:21
author: edinw
@
*/

/*
**  注意：本题与主站 110 题相同：https://leetcode-cn.com/problems/balanced-binary-tree/
**
**  Given a binary tree, determine if it is height-balanced.
**
**  For this problem, a height-balanced binary tree is defined as:
**
**  a binary tree in which the left and right subtrees of every node differ in height by no more than 1.
*/

using namespace binary_ordinary_tree;

namespace leetcode_cpp {
class Solution {
public:
    bool isBalanced(TreeNode *root) {
        if (nullptr == root) {
            return true;
        }
        int leftHeight = getHeight(root->left);
        int rightHeight = getHeight(root->right);
        return std::abs(rightHeight - leftHeight) < 2 && isBalanced(root->left) && isBalanced(root->right);
    }

private:
    int getHeight(TreeNode *root) {
        if (nullptr == root) {
            return 0;
        }
        return std::max(getHeight(root->left), getHeight(root->right)) + 1;
    }
};

class Solution2 {
public:
    bool isBalanced(TreeNode *root) {
        return -1 != getHeight(root);
    }

private:
    int getHeight(TreeNode *node) {
        if (nullptr == node) {
            return 0;
        }
        int leftHeight = 0, rightHeight = 0;
        if ((leftHeight = getHeight(node->left)) == -1 ||
            (rightHeight = getHeight(node->right) == -1) ||
            std::abs(leftHeight - rightHeight) > 1) {
            return -1;
        }
        return std::max(leftHeight, rightHeight) + 1;
    }
};
}