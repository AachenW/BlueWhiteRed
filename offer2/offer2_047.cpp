#include <vector>
#include <iostream>
#include <deque>

/*
@
LeetCode 剑指offerⅡ
time: 2022-01-16 20:03:13
author: edinw
@
*/

/*
注意：本题与主站 814 题相同：https://leetcode-cn.com/problems/binary-tree-pruning/

给定一个二叉树 根节点 root ，树的每个节点的值要么是 0，要么是 1。请剪除该二叉树中所有节点的值为 0 的子树。

节点 node 的子树为 node 本身，以及所有 node 的后代。
*/

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

namespace leetcode_cpp {
class Solution {
public:
    TreeNode* pruneTree(TreeNode *root) {
        if (nullptr == root) {
            return nullptr;
        }
        TreeNode *leftTree = pruneTree(root->left);
        TreeNode *rightTree = pruneTree(root->right);
        // 当该二叉树判断为零树（左右指针指向空指针且其根节点的值为 0），则返回空指针，反之则返回根节点。
        if (0 == root->val && nullptr == leftTree && nullptr == rightTree) {
            return nullptr;
        }
        root->left = leftTree;
        root->right = rightTree;
        return root;
    }
};

class Solution2 {
public:
    TreeNode* pruneTree(TreeNode *root) {
        return containsOne(root) ? root : nullptr;
    }

private:
    bool containsOne(TreeNode *node) {
        if (nullptr == node) {
            return false;
        }
        bool leftContainsOne = containsOne(node->left);
        bool rightContainsOne = containsOne(node->right);
        if (!leftContainsOne) {
            node->left = nullptr;
        }
        if (!rightContainsOne) {
            node->right = nullptr;
        }
        return node->val == 1 | leftContainsOne | rightContainsOne;
    }
};
}